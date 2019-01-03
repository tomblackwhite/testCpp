#include<iostream>
#include<algorithm>

int c=0;

int main()
{
    int x[]={1,6,5,8,9};
    std::sort(x,x+5,[] (int l,int r){
        c++;
        return (l<r);
    });
    std::cout<<c;
    return 0;
}
class comp{
    public:

        bool operator()(int l,int r)
        {
            if(l>r)
            c++;
            return (l<r);
        }
};
