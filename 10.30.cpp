/*10.30习题答案*/
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
int main()
{
    std::istream_iterator<int> in(std::cin),end;
    std::ostream_iterator<int> out(std::cout," ");
    std::vector<int> vec(in,end);
    std::cout << std::endl;
    copy(vec.cbegin(), vec.cend(), out);
    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(),out);
    return 0;
}