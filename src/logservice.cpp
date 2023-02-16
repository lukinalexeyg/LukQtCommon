#include "logservice.h"

#include "chars.h"
#include "macros.h"
#include "utils.h"

#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QMutex>
#include <QTextStream>
#include <QThread>
#include <QFile>

static constexpr int s_maxThreadNameLength = 16;
static constexpr int s_maxFileSize = 1048576;

static const QLatin1String s_logFileExtension("log");
static const QLatin1String s_startSuffix("-start");
static const QStringList s_letters = {"D", "W", "C", "F", "I"};

static QString s_dirPath;
static QFile s_file;
static QMutex s_mutex;



QDateTime setFile(const QDateTime &dateTime = QDateTime())
{
    const bool isDateTimeNull = dateTime.isNull();

    const QDateTime _dateTime = isDateTimeNull ? QDateTime::currentDateTime() : dateTime;

    const QString dirPath = QString("%1/%2").arg(s_dirPath, _dateTime.toString(QStringLiteral("yy-MM-dd")));
    QDir().mkpath(dirPath);

    const QString filePath = QString("%1/%2%3.%4").arg(dirPath,
                                                       _dateTime.toString(QStringLiteral("yyMMdd-hhmmss")),
                                                       isDateTimeNull ? s_startSuffix : QString(),
                                                       s_logFileExtension);

    s_file.setFileName(filePath);
    s_file.open(QFile::WriteOnly | QFile::Append | QFile::Text) ? _dateTime : QDateTime();

    return _dateTime;
}



void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message)
{
    QMutexLocker mutexLocker(&s_mutex);
    Q_UNUSED(context)

    const QDateTime currentDateTime = QDateTime::currentDateTime();
    const QString dateTimeString = currentDateTime.toString(QStringLiteral("yy-MM-dd - hh:mm:ss.zzz"));
    const QString threadIdString = Utils::numberToString(r_cast(qint64, QThread::currentThreadId()), 5);
    QString threadName = !QThread::currentThread()->objectName().isEmpty()
            ? QThread::currentThread()->objectName()
            : QStringLiteral("Qt internal");
    threadName = threadName.left(s_maxThreadNameLength);

    const QString _message = QString("%1 | %2 - %3 | %4 | %5")
            .arg(dateTimeString, threadIdString, threadName, s_letters.at(type), message);

    if (s_file.size() + _message.toUtf8().count() > s_maxFileSize) {
        s_file.close();
        setFile(currentDateTime);
    }

    QTextStream logTextStream(&s_file);
    logTextStream << _message << endl;
    s_file.flush();
}



LogService::LogService(const QString &dirPath, QObject *parent)
    : QObject{parent}
{
    s_dirPath = dirPath;

    m_startDateTime = setFile();

    qInstallMessageHandler(messageHandler);
}



LogService::~LogService()
{
    s_file.close();

    qInstallMessageHandler(nullptr);
}
