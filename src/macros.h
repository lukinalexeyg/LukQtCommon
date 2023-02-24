#ifndef MACROS_H
#define MACROS_H

#define STR(s) #s

#define QL1(s) QLatin1String(s)

#define QSL(s) QStringLiteral(s)

#define STATIC_CONST_LATIN1_STR(s) static const QLatin1String s(STR(s))

#define SIZE_OF_ARRAY(array) (sizeof((array)) / sizeof((array)[0]))

#define S_CAST(type, value) static_cast<type>(value)
#define S_CAST_INT(value) S_CAST(int, value)
#define S_CAST_UINT(value) S_CAST(uint, value)
#define S_CAST_REAL(value) S_CAST(qreal, value)
#define UINT_N1 S_CAST_UINT(-1)

#define D_CAST(type, value) dynamic_cast<type>(value)

#define R_CAST(type, value) reinterpret_cast<type>(value)
#define R_CAST_LPCSTR(value) R_CAST(const char*, value)
#define R_CAST_LPCWSTR(value) R_CAST(const wchar_t*, value)

#define q_cast(type, value) qobject_cast<type>(value)
#define SET_QOBJECT(type, a, b) type a = q_cast(type, b)

#define foreach_index_inc(i, count) for (int i = 0; i < count; ++i)
#define foreach_index_dec(i, count) for (int i = count-1; i >= 0; --i)

#define foreach_index_u_inc(i, count) for (ulong i = 0; i < count; ++i)
#define foreach_index_u_dec(i, count) for (ulong i = count-1; i >= 0; --i)

#define foreach_element(element, container) for (const auto element : container)
#define foreach_element_ref(element, container) for (const auto &element : container)

#define foreach_element_const(element, container) for (const auto element : qAsConst(container))
#define foreach_element_const_ref(element, container) for (const auto &element : qAsConst(container))

#define foreach_iterator(it, container) for (auto it = container.begin(); it != container.end();)
#define foreach_iterator_inc(it, container) for (auto it = container.begin(); it != container.end(); ++it)
#define foreach_iterator_dec(it, container) for (auto it = container.end()-1; it != container.begin()-1; --it)

#define foreach_iterator_ptr(it, container) for (auto it = container->begin(); it != container->end();)
#define foreach_iterator_ptr_inc(it, container) for (auto it = container->begin(); it != container->end(); ++it)
#define foreach_iterator_ptr_dec(it, container) for (auto it = container->end()-1; it != container->begin()-1; --it)

#define foreach_iterator_const(it, container) for (auto it = container.cbegin(); it != container.cend();)
#define foreach_iterator_const_inc(it, container) for (auto it = container.cbegin(); it != container.cend(); ++it)
#define foreach_iterator_const_dec(it, container) for (auto it = container.cend()-1; it != container.cbegin()-1; --it)

#define foreach_iterator_const_ptr(it, container) for (auto it = container->cbegin(); it != container->cend();)
#define foreach_iterator_const_ptr_inc(it, container) for (auto it = container->cbegin(); it != container->cend(); ++it)
#define foreach_iterator_const_ptr_dec(it, container) for (auto it = container->cend()-1; it != container->cbegin()-1; --it)

#define SORT(container) std::sort(container.begin(), container.end())
#define SORT_FUNC(container, func) std::sort(container.begin(), container.end(), func)

#endif // MACROS_H
