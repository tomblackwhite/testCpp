/* C++ primer 11.3 */
#include<list>
#include<iostream>
#include<map>
#include<set>
#include<forward_list>
int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An",
                                     "A", "the"};
    std::string word;
    while(std::cin>>word)
    {
        if(exclude.find(word)==exclude.end())
        {
            ++word_count[word];
        }
    }
    for(const auto &w:word_count)
        std::cout << w.first << ' ' << w.second<<std::endl;
    return 0;
}