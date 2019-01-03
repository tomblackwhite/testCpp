/* Quote */
#include "Quote.hpp"
double print_total(std::ostream &os,const Quote &item,
std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: "
       << ret << std::endl;
    return ret;
}
double Bulk_quote::net_price(std::size_t n) const
{
    if(n>=quantity)
        return n * (1 - discount) * price;
    else
        return n * price;
}
void Basket::add_item(const Quote &sale)
{
    items.insert(std::shared_ptr<Quote>(sale.clone()));
}
void Basket::add_item(Quote &&sale)
{
    items.insert(
        std::shared_ptr<Quote>(std::move(sale).clone()));
}