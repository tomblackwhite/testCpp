/*10.33习题答案*/
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
int main()
{
    std::ifstream in("datainput.txt");
    std::ofstream outodd("dataoutput1.txt");
    std::ofstream outeven("dataoutput2.txt");
    std::istream_iterator<int> in_iterator(in),end;
    std::ostream_iterator<int> out_iterator_odd(outodd, " ");
    std::ostream_iterator<int> out_itertor_even(outeven, " ");
    std::vector<int> vec(in_iterator, end);
    for_each(vec.cbegin(), vec.cend(), [&](int x) {
        if(x%2==0)
        {
            *out_itertor_even = x;
            outeven << std::endl;
        }
        else
        {
            *out_iterator_odd = x;
            outodd << std::endl;
        }
    });
    return 0;
}