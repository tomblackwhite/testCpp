/* C++ primer 11.38 */
#include<map>
#include<iostream>
#include<string>
#include<unordered_map>
using std::string;
using std::cin;
using std::cout;
int main()
{
    std::unordered_map<string, size_t> word_count;
    string word;
    while(cin>>word)
        ++word_count[word];
    for(const auto &w:word_count)
    {
        cout << w.first << ' ' << w.second;
        cout << std::endl;
    }
    return 0;
}