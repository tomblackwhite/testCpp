/* C++ Primer 13.48*/
#include "String.hpp"
#include <vector>
#include <iostream>
int main()
{
    std::vector<String> power{"23", "shgal", "ahsd",
                              "ahs", "375894"};
    power.push_back(String("hljll;l;"));
    for(auto &str:power)
    {
       for(auto &c:str)
           std::cout << c;
        std::cout
            << ' ';
    }
    return 0;
}