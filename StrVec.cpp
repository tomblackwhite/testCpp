
#include "StrVec.hpp"
std::allocator<std::string> StrVec::alloc;
std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    if(elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcaptivity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcaptivity);
    auto dest = uninitialized_copy(std::make_move_iterator(begin()),
                                   std::make_move_iterator(end()),
                                   newdata);
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcaptivity;
}

StrVec::StrVec(const StrVec& sv)
{
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    elements = newdata.first;
    first_free = newdata.second;
    cap = first_free;
}

StrVec& StrVec::operator=(const StrVec& sv)
{
    auto data = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string &str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void StrVec::push_back(std::string &&str)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(str));
}

StrVec::StrVec(StrVec &&sv) noexcept
{
    first_free = sv.first_free;
    elements = sv.elements;
    cap = sv.cap;
    sv.first_free = sv.elements = sv.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&sv) noexcept
{
    if(this!=&sv)
    {
        free();
        elements = sv.elements;
        first_free = sv.first_free;
        cap = sv.cap;
        sv.elements = sv.first_free = sv.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec &lhs,const StrVec &rhs)
{
    if(lhs.size()==lhs.size())
    {
        auto ltemp = lhs.elements;
        auto rtemp = rhs.elements;
        while(ltemp!=lhs.first_free)
        {
            if(*ltemp!=*rtemp)
                return false;
            ++ltemp;
            ++rtemp;
        }
        return true;
    }
    else
        return false;
}

bool operator!=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs,const StrVec &rhs)
{
    for (auto ltemp = lhs.elements, rtemp = rhs.elements;
         ltemp != lhs.first_free && rtemp != rhs.first_free;
         ++ltemp,++rtemp)
        if(*ltemp<*rtemp)
            return true;
        else if(*ltemp>*rtemp)
            return false;
    return (lhs.size() < rhs.size()) ? true : false;
}

bool operator<=(const StrVec &lhs,const StrVec &rhs)
{
    for (auto ltemp = lhs.elements, rtemp = rhs.elements;
         ltemp != lhs.first_free && rtemp != rhs.first_free;
         ++ltemp,++rtemp)
        if(*ltemp<*rtemp)
            return true;
        else if(*ltemp>*rtemp)
            return false;
    return (lhs.size() > rhs.size()) ? false : true;
}

bool operator>(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const StrVec &lhs,const StrVec &rhs)
{
    return !(lhs < rhs);
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), , il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}