#ifndef LOGSERVICE_H
#define LOGSERVICE_H

#include <QDateTime>
#include <QObject>

class LogService : public QObject
{
    Q_OBJECT

public:
    explicit LogService(const QString &dirPath, QObject *parent = nullptr);

public:
    QDateTime startDateTime() const { return m_startDateTime; }

private:
    QDateTime m_startDateTime;

private:
    Q_DISABLE_COPY(LogService)

    ~LogService();
};

#endif // LOGSERVICE_H
