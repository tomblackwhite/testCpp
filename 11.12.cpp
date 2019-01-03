/* C++ primer 11.12 */
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
    std::vector<std::pair<std::string, int>> vecp;
    std::string s;
    int x;
    while(std::cin>>s>>x)
    {
        vecp.push_back({s,x});
    }
    for(const auto &val:vecp)
    {
        std::cout << val.first << ' ' << val.second;
        std::cout << std::endl;
    }
    return 0;
}