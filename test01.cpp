#include<string>
#include<iostream>
#include<forward_list>
#include<vector>
#include<list>
using namespace std;
void fun(forward_list<string>&, string, string);
int main()
{
    /*forward_list<int> fls = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto preiter = fls.cbefore_begin();
    auto iter = fls.cbegin();
    while(iter!=fls.cend())
    {
        if((*iter)%2!=0)
        {
            iter = fls.erase_after(preiter);
        }
        else
        {
            preiter = iter;
            ++iter;
        }
    }
    for(int i:fls)
    {
        cout << i << ' ';
    }*/
    //forward_list<string> flstr{"1", "2", "3", "4", "5", "6", "7"};
    //fun(flstr, "g", "sg");
    //for(auto react:flstr)
    //    cout << react << ' ';
    //vector<char> vc{'a', 'b', 'c', 'd', 'e', 'f'};
    //string s(vc.cbegin(), vc.cend());
    //cout << s;
    
    return 0;
}
void fun(forward_list<string> &fls, string s1, string s2)
{
    auto preiter = fls.cbefore_begin();
    auto iter = fls.cbegin();
    while(iter!=fls.cend())
    {
        if(*iter==s1)
        {
            break;
        }
        else
        {
            preiter = iter;
            ++iter;
        }
    }
    if(iter==fls.cend())
    fls.insert_after(preiter, s2);
    else
    {
        fls.insert_after(iter, s2);
    }
}
