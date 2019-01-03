/* C++ Primer 12.26 */
#include<string>
#include<iostream>
#include<memory>
int main()
{
    std::allocator<std::string> a;
    unsigned n=0;
    std::cin >> n;
    auto const p=a.allocate(n);
    auto q = p;
    std::string word;
    while(std::cin>>word&&q!=p+n)
    {
        a.construct(q++, word);
    }
    const size_t size = q - p;
    for (auto i = p; i != q;i++)
    {
        std::cout << *i << ' ';
    }
    std::cout << std::endl
              << size;
    while(q!=p)
        a.destroy(--q);
    a.deallocate(p, n);
    return 0;
}