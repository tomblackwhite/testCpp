/* C++ primer 11.33 */
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include<exception>
void build_map(std::map<std::string, std::string> &, std::ifstream &);
const std::string &transform(const std::string &s,
                             const std::map<std::string, std::string> &m);
int main()
{
    std::ifstream map_file("datainput.txt");
    std::map<std::string, std::string> map;
    build_map(map, map_file);
    std::ifstream inop("dataoutput1.txt");
    std::string text;
    while(getline(inop,text))
    {
        std::istringstream stream(text);
        std::string word;
        bool firstword = true;
        while(stream>>word)
        {
            if(firstword)
                firstword = false;
            else
                std::cout << ' ';
            std::cout << transform(word, map);
        }
        std::cout << std::endl;
    }
    return 0;
}
void build_map(std::map<std::string, std::string> &result_map,
               std::ifstream &map_file)
{
    std::string key, value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
            result_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    }
}
const std::string &transform(const std::string &s,
                             const std::map<std::string, std::string> &m)
{
    auto map_it = m.find(s);
    if(map_it!=m.cend())
        return map_it->second;
    else
        return s;
}