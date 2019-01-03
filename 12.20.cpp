/* C++ Primer 12.20 */
#include<iostream>
#include<string>
#include<fstream>
#include "StrBlob.hpp"
int main()
{
    std::fstream fin("datainput.txt");
    StrBlob sb;
    std::string word;
    while(fin>>word)
        sb.push_back(word);

    auto val = sb.cbegin();
    for (StrBlob::size_type i=0; i < sb.size();++i)
    {
        std::cout << val.deref() << ' ';
        val.incr();
    }
    return 0;
}