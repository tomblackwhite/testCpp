#include<memory>
#include<iostream>
struct A{
    int c = 0;
};
struct B :public A
{
    int cb = 0;
};
int main()
{
    A *a = new A[5];
    B *b = new B[5];
    a = b;
    std::cout << (a + 3)->cb << std::endl;
}
