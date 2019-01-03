/*10.32习题答案*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
class Sales_item
{
  private:
    std::string bookNum;
    double revenue = 0.0;
    unsigned units_sold = 0;

  public:
    Sales_item(std::string s, unsigned cnt, double price) : 
        bookNum(s), revenue(price), units_sold(cnt) {}
    Sales_item() : Sales_item("", 0, 0){};
    Sales_item(std::string s) : Sales_item(s, 0, 0) {}
    std::string isbn() const { return bookNum; }
};