/*10.29习题答案*/
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
int main()
{
    std::ifstream fs("data.txt");
    std::istream_iterator<std::string> in(fs),end;
    std::vector<std::string> vecstr(in,end);
    std::ostream_iterator<std::string> out_iterator(std::cout, " ");
    copy(vecstr.cbegin(), vecstr.cend(), out_iterator);
    return 0;
}