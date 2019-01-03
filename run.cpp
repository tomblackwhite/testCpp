#include<iostream>
bool isrun(int x);
int main()
{
    int x = 0;
    while(std::cin>>x)
    {
        if(isrun(x))
            std::cout << "yes" << std::endl;

        else
        {
            std::cout << "no" << std::endl;
        }
        
    }
    return 0;
}

bool isrun(int x)
{
    bool is = true;
    if(x>0)
    {
        if(x%100==0)
        {
            if(x%400==0)
                is = true;
            
            else
            {
                is = false;
            }
            
        }
        
        else
        {
            if(x%4==0)
                is = true;
            
            else
            {
                is = false;
            }
            
        }
    }
    
    else if(x<0)
    {
        int y = -x;
        if(y%100==1)
        {
            if(y%400==1)
                is = true;
            
            else
            {
                is = false;
            }
            
        }
        
        else
        {
            if(y%4==1)
                is = true;
            
            else
            {
                is = false;
            }
            
        }
        
    }
    return is;
}