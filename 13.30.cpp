/* C++ Primer 13.30 */
#include<iostream>
#include <algorithm>
#include<string>
#include "HasPtr.hpp"
#include<vector>
int main()
{
    std::vector<HasPtr> vec;
    std::string word;
    while(std::cin>>word)
    {
        vec.push_back(word);
    }
    sort(vec.begin(),vec.end());
    
    return 0;
}