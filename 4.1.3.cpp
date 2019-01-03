#include<iostream>
#include<vector>
#include<utility>
#include<array>
using MaxArray = std::array<int, 3>;
using OriginArray = std::vector<int>::const_iterator;
MaxArray findMaximumArray(const OriginArray &, int, int);
MaxArray findMaxcrossArray(const OriginArray &, int,int, int);
int main()
{
    std::vector<int> vec{2, 3, 4, 5, -3, -6, -8};
    MaxArray array=findMaximumArray(vec.cbegin(),0,vec.size());
    std::cout << array[0]<<' '<<array[1]<<' '<<array[2];
    return 0;
}
MaxArray findMaximumArray(const OriginArray &oa, int low, int high)
{
    if(low==high)
        return MaxArray{low, high, *(oa + low)};
    
    else
    {
        int mid = (low + high) / 2;
        MaxArray leftArray = findMaximumArray(oa, low, mid);
        MaxArray rightArray = findMaximumArray(oa, mid, high);
        MaxArray crossArray = findMaxcrossArray(oa, low, mid, high);
        if(leftArray[2]>=rightArray[2]&&leftArray[2]>=crossArray[2])
        {
            return leftArray;
        }
        else if(rightArray[2]>=leftArray[2]&&rightArray[2]>=crossArray[2])
        {
            return rightArray;
        }
        else
            return crossArray;
    }
    
}

MaxArray findMaxcrossArray(const OriginArray &oa,int low,int mid,int high)
{
    int leftResult=0,rightResult=0,maxLeft=0,maxRight=0;
    int sum=0;
    for (int i = mid - 1;i>=low;--i)
    {
        sum += *(oa + i);
        if(sum>leftResult)
        {
            leftResult = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for (int i = mid; i < high;++i)
    {
        sum += *(oa + i);
        if(sum>rightResult)
        {
            rightResult = sum;
            maxRight = i;
        }
    }
    return MaxArray{maxLeft, maxRight, (leftResult + rightResult)};
}
