/* C++ primer 11.20 */
#include<set>
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
#include<utility>
int main()
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while(std::cin>>word)
        ++word_count.insert({word, 0}).first->second;
    for(const auto &val:word_count)
    {
        std::cout << val.first << ' ' << val.second;
        std::cout << std::endl;
    }
    return 0;
}