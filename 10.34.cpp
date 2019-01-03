/* C++ primer 习题10.34 */
#include<iterator>
#include<algorithm>
#include<vector>
#include<iostream>
int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::ostream_iterator<int> out(std::cout, " ");
    copy(vec.crbegin(), vec.crend(), out);
    return 0;
}