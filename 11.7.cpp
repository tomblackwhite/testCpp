/* C++ pimer 11.7 */
#include<iterator>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
int main()
{
    std::string last_name;
    std::map < std::string, std::vector<std::string>>family;
    while(std::cin>>last_name)
    {
        std::string children_name;
        while(std::cin >> children_name)
        family[last_name].push_back(children_name);
        std::cin.clear();
    }
    for(const auto &val:family)
    {
        std::cout << val.first << ' ';
        copy(val.second.cbegin(), val.second.cend(),
             std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }
    return 0;
}