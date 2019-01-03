/*10.31习题答案*/
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
int main()
{
    std::vector<int> vec{1, 2, 3, 5, 5, 6, 6, 89};
    std::ostream_iterator<int> out(std::cout, " ");
    unique_copy(vec.cbegin(), vec.cend(), out);
    return 0;
}