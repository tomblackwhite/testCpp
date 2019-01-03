/* C++ primer 11.31 */
#include <iostream>
#include <iterator>
#include <map>
#include <string>
int main()
{
    std::multimap<std::string, std::string> author{
        {"Tom", "shan"},
        {"Sam", "you"},
        {"Tom", "agsd"},
        {"Sam", "zhg"},
        {"Jack", "sfd"}};
    auto ite = author.find("Tom");
    while (ite != author.cend())
    {
        author.erase(ite);
        ite = author.find("Tom");
    }
    for (const auto &val : author)
    {
        std::cout << val.first << ' ' << val.second << std::endl;
    }
    return 0;
}