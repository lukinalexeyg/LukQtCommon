#ifndef MACROS_H
#define MACROS_H

#define STR(x) #x

#define BOOL_STR(x) x ? "true" : "false"

#define QL1(string) QLatin1String(string)

#define QSL(string) QStringLiteral(string)

#define size_of_array(array) (sizeof((array)) / sizeof((array)[0]))

#define s_cast(type, value) static_cast<type>(value)
#define s_cast_int(value) s_cast(int, value)
#define s_cast_uint(value) s_cast(uint, value)
#define s_cast_real(value) s_cast(qreal, value)
#define UINT_N1 s_cast_uint(-1)

#define d_cast(type, value) dynamic_cast<type>(value)

#define r_cast(type, value) reinterpret_cast<type>(value)
#define r_cast_lpcstr(value) r_cast(const char*, value)
#define r_cast_lpcwstr(value) r_cast(const wchar_t*, value)

#define q_cast(type, value) qobject_cast<type>(value)

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

#define sort_(container) std::sort(container.begin(), container.end())
#define sort_func(container, func) std::sort(container.begin(), container.end(), func)

#endif // MACROS_H
