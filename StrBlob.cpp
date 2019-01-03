/* StrBlob.cpp */
#include "StrBlob.hpp"

/* StrBlob */
StrBlob::StrBlob(const StrBlob& sb):data(new vector<string>(*sb.data)) { }
StrBlob::StrBlob() : data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(StrBlob::size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front() const
{
    check(0, "font on empty StrBlob");
    return data->front();
}

string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlob& StrBlob::operator=(StrBlob& sb)
{
    auto newp = std::make_shared<vector<string>>(*sb.data);
    data = newp;
    return *this;
}

/* StrBlobPtr */
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

std::string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

std::shared_ptr<vector<string>>
StrBlobPtr::check(std::size_t i,const string &msg)const
{
    auto rect = wptr.lock();
    if(!rect)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i>=rect->size())
        throw std::out_of_range(msg);
    return rect;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
/* ConstStrBlobPtr */
const std::string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

const std::shared_ptr<vector<string>>
ConstStrBlobPtr::check(std::size_t i,const string &msg)const
{
    auto rect = wptr.lock();
    if(!rect)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i>=rect->size())
        throw std::out_of_range(msg);
    return rect;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
    --curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

inline ConstStrBlobPtr StrBlob::cbegin() const
{
    return ConstStrBlobPtr(*this);
}

inline ConstStrBlobPtr StrBlob::cend() const
{
    return ConstStrBlobPtr(*this, data->size());
}

bool operator==(const StrBlob &lhs,const StrBlob &rhs)
{
    return (*lhs.data == *rhs.data) ? true : false;
}

bool operator!=(const StrBlob &lhs,const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    if(lhs.wptr.lock()==rhs.wptr.lock()&&lhs.curr==rhs.curr)
        return true;
    else
        return false;
}

bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator==(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    if(lhs.wptr.lock()==rhs.wptr.lock()&&lhs.curr==rhs.curr)
        return true;
    else
        return false;
}

bool operator!=(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs,const StrBlob &rhs)
{
    return (*lhs.data < *rhs.data);
}

bool operator<=(const StrBlob &lhs,const StrBlob &rhs)
{
    return (*lhs.data <= *rhs.data);
}

bool operator>(const StrBlob &lhs,const StrBlob &rhs)
{
    return (*lhs.data > *rhs.data);
}

bool operator>=(const StrBlob &lhs,const StrBlob &rhs)
{
    return (*lhs.data >= *rhs.data);
}

bool operator<(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    if(lhs.wptr.lock()!=rhs.wptr.lock())
        throw std::runtime_error("left and right are to one Str");
    else
        return (lhs.curr < rhs.curr) ? true : false;
}

bool operator<=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    if(lhs.wptr.lock()!=rhs.wptr.lock())
        throw std::runtime_error("left and right are to one Str");
    else
        return (lhs.curr <= rhs.curr) ? true : false;
}

bool operator>(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

bool operator<(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    if(lhs.wptr.lock()!=rhs.wptr.lock())
        throw std::runtime_error("left and right are to one Str");
    else
        return (lhs.curr < rhs.curr) ? true : false;
}

bool operator<=(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    if(lhs.wptr.lock()!=rhs.wptr.lock())
        throw std::runtime_error("left and right are to one Str");
    else
        return (lhs.curr <= rhs.curr) ? true : false;
}

bool operator>(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const ConstStrBlobPtr &lhs,const ConstStrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

StrBlobPtr &operator+(StrBlobPtr &lhs, size_t n)
{
    lhs.curr += 5;
    return lhs;
}

StrBlobPtr& operator+(size_t n,StrBlobPtr &rhs)
{
    rhs += n;
    return rhs;
}

StrBlobPtr& operator-(StrBlobPtr &lhs,size_t n)
{
    lhs -= n;
    return lhs;
}

ConstStrBlobPtr& operator+(ConstStrBlobPtr &lhs, size_t n)
{
    lhs.curr += 5;
    return lhs;
}

ConstStrBlobPtr& operator+(size_t n,ConstStrBlobPtr &rhs)
{
    rhs += n;
    return rhs;
}

ConstStrBlobPtr& operator-(ConstStrBlobPtr &lhs,size_t n)
{
    lhs -= n;
    return lhs;
}