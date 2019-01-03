/* 10.36习题 */
#include<list>
#include<iostream>
#include<iterator>
#include<algorithm>
int main()
{
    std::list<int> lis{1, 2, 4, 0, 8, 0, 9};
    auto iterator = find(lis.crbegin(), lis.crend(), 0);
    copy(lis.crbegin(), iterator,std::ostream_iterator<int>(std::cout," "));
    return 0;
}