
#include "String.hpp"
std::allocator<char> String::alloc;
void String::free()
{
    auto p = elements;
    std::for_each(elements, first_free,
                  [p](const char &c) mutable { String::alloc.destroy(p++); });
    alloc.deallocate(elements, first_free - elements);
}

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
    auto newdata = alloc.allocate(e - b);
    return {newdata, std::uninitialized_copy(b, e, newdata)};
}

String::String(const String &str)
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = newdata.second;
}

String &String::operator=(const String &str)
{
    auto newdata = alloc_n_copy(str.begin(), str.end());
    free();
    elements = newdata.first;
    first_free = newdata.second;
    return *this;
}

String::String(const char *str)
{
    int x = 0;
    for (auto temptr = str; *temptr != '\0'; x++, ++temptr)
        ;
    auto newdata = alloc_n_copy(str, str + x);
    elements = newdata.first;
    first_free = newdata.second;
}

String::String(String &&str) noexcept
{
    elements = str.elements;
    first_free = str.first_free;
    str.elements = str.first_free = nullptr;
    std::cout << "ss" << ' ';
}

String &String::operator=(String &&str) noexcept
{
    if (this != &str)
    {
        free();
        elements = str.elements;
        first_free = str.first_free;
        str.elements = str.first_free = nullptr;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    for (const auto &c : str)
    {
        os << c;
    }
    return os;
}

bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() == lhs.size())
    {
        for (auto ltemp = lhs.elements, rtemp = rhs.elements;
             ltemp != lhs.first_free; ++ltemp, ++rtemp)
            if (*ltemp != *rtemp)
                return false;
        return true;
    }
    else
        return false;
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    for (auto ltemp = lhs.elements, rtemp = rhs.elements;
         ltemp != lhs.first_free && rtemp != rhs.first_free;
         ++ltemp, ++rtemp)
        if (*ltemp < *rtemp)
            return true;
        else if (*ltemp > *rtemp)
            return false;
    return (lhs.size() < rhs.size()) ? true : false;
}

bool operator<=(const String &lhs,const String &rhs)
{
    for (auto ltemp = lhs.elements, rtemp = rhs.elements;
         ltemp != lhs.first_free && rtemp != rhs.first_free;
         ++ltemp, ++rtemp)
        if (*ltemp < *rtemp)
            return true;
        else if (*ltemp > *rtemp)
            return false;
    return (lhs.size() <= rhs.size()) ? true : false;
}

bool operator>(const String &lhs,const String &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const String &lhs,const String &rhs)
{
    return !(lhs < rhs);
}