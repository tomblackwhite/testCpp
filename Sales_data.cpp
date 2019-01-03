#include "Sales_data.hpp"
std::ostream& operator<<(std::ostream &os,const Sales_data &s)
{
    os << s.bookNo << ' '
     << s.units_sold << ' ' << s.revenue;
    return os;
}

std::istream& operator>>(std::istream &is,Sales_data &s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    if(is)
        s.revenue = price * s.units_sold;
    else
        s = Sales_data();
    return is;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &s)
{
    units_sold += s.units_sold;
    revenue += s.revenue;
    return *this;
}

Sales_data& Sales_data::operator=(const std::string &str)
{
    boolNo = str;
}