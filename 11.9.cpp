/* C++ primer 11.9 */
#include<iostream>
#include<map>
#include<list>
#include<string>
#include<algorithm>
#include<iterator>
#include<vector>
int main()
{
    std::map<std::vector<int>::iterator, int> maps;
    std::map<std::list<int>::iterator, int> mapx;
    std::map<std::string, std::list<unsigned>> map1;
    std::string word;
    unsigned line_n;
    while(std::cin>>word>>line_n)
    {
        map1[word].push_back(line_n);
    }
    for(const auto &val:map1)
    {
        std::cout << val.first << ' ';
        copy(val.second.cbegin(), val.second.cend(),
             std::ostream_iterator<unsigned>(std::cout, " "));
    }
    return 0;
}