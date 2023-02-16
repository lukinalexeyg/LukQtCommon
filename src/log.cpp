#include "log.h"

#ifdef Q_OS_WIN

#include <Windows.h>
#include <comdef.h>

QString lastErrorString()
{
    const DWORD dwCode = GetLastError();

    if (dwCode == 0)
        return QString::number(dwCode);

    const _com_error comError(dwCode);

    return QString("%1:%2")
            .arg(dwCode)
            .arg(QString::fromWCharArray(comError.ErrorMessage()));
}

#endif // Q_OS_WIN
