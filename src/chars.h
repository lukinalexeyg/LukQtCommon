#ifndef CHARS_H
#define CHARS_H

#include <QChar>

namespace Chars {
    static const QLatin1Char space(' ');
    static const QLatin1Char exclam('!');
    static const QLatin1Char numberSign('#');
    static const QLatin1Char dollar('$');
    static const QLatin1Char percent('%');
    static const QLatin1Char ampersand('&');
    static const QLatin1Char asterisk('*');
    static const QLatin1Char plus('+');
    static const QLatin1Char comma(',');
    static const QLatin1Char minus('-');
    static const QLatin1Char dot('.');
    static const QLatin1Char colon(':');
    static const QLatin1Char semicolon(';');
    static const QLatin1Char equal('=');
    static const QLatin1Char question('?');
    static const QLatin1Char at('@');
    static const QLatin1Char circum('^');
    static const QLatin1Char underscore('_');
    static const QLatin1Char bar('|');
    static const QLatin1Char tilda('~');

    static const QLatin1Char slash('/');
    static const QLatin1Char backslash('\\');

    namespace Quote {
        static const QLatin1Char Double('\"');
        static const QLatin1Char single('\'');
        static const QLatin1Char left('`');
    }

    namespace Number {
        static const QLatin1Char zero('0');
        static const QLatin1Char one('1');
        static const QLatin1Char two('2');
        static const QLatin1Char three('3');
        static const QLatin1Char four('4');
        static const QLatin1Char five('5');
        static const QLatin1Char six('6');
        static const QLatin1Char seven('7');
        static const QLatin1Char eight('8');
        static const QLatin1Char nine('9');
    }

    static const QLatin1Char parenthesisLeft('(');
    static const QLatin1Char parenthesisRight(')');

    static const QLatin1Char less('<');
    static const QLatin1Char greater('>');

    static const QLatin1Char bracketLeft('[');
    static const QLatin1Char bracketRight(']');

    static const QLatin1Char braceLeft('{');
    static const QLatin1Char braceRight('}');
}

#endif // CHARS_H
