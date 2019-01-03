#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<numeric>
using namespace std;
int main()
{
    vector<int> vecint{1, 2, 3, 4, 4, 5, 5, 6};
    list<int> lisint;
    unique_copy(vecint.cbegin(), vecint.cend(), back_inserter(lisint));
    for_each(lisint.cbegin(), lisint.cend(), [](const int x) { cout << x << ' '; });
    return 0;
}