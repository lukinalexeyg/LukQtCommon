#ifndef LOG_H
#define LOG_H

#include <QDebug>

#define FUNCTION_LOG FunctionLog functionLog(__FUNCTION__)

class FunctionLog
{
public:
    explicit FunctionLog(const char *function) : m_function(function) { qDebug("+ %s", function); }
    ~FunctionLog() { qDebug("- %s", m_function); }

private:
    const char* m_function;
};

#define DEBUG_LOG qDebug().noquote() << __FUNCTION__ <<
#define DEBUG_LOG_ qDebug().noquote() << __FUNCTION__

#define INFO_LOG qInfo().noquote() << __FUNCTION__ <<
#define INFO_LOG_ qInfo().noquote() << __FUNCTION__

#define FUNCTION_LINE QString("%1:%2:").arg(__FUNCTION__).arg(__LINE__)

#ifdef Q_OS_WIN
QString lastErrorString();
#define FUNCTION_LINE_E QString("%1 [%2]").arg(FUNCTION_LINE).arg(lastErrorString())
#else
#define FUNCTION_LINE_E FUNCTION_LINE
#endif

#define WARNING_LOG qWarning().noquote() << FUNCTION_LINE <<
#define WARNING_LOG_ qWarning().noquote() << FUNCTION_LINE
#define WARNING_LOG_E qWarning().noquote() << FUNCTION_LINE_E <<
#define WARNING_LOG_E_ qWarning().noquote() << FUNCTION_LINE_E

#define CRITICAL_LOG qCritical().noquote() << FUNCTION_LINE <<
#define CRITICAL_LOG_E qCritical().noquote() << FUNCTION_LINE_E <<

#define FATAL_LOG qFatal().noquote() << FUNCTION_LINE <<
#define FATAL_LOG_E qFatal().noquote() << FUNCTION_LINE_E <<

#define dump(x) QString("{%1: %2}").arg(#x).arg(x)

#endif // LOG_H
