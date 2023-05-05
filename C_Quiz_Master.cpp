#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long a,b;
    cin>>a>>b;
    long long int array[a];
    for(long long int i=0;i<a;i++)
    {
        cin>>array[i];
    }
    sort(array,array+a);
    long long int mini=INT_MAX;
    long long int maxi=INT_MIN;

    bool flag=false;
    
    for(int i=2;i<=b;++i)
    {
        flag=false;
        for(int j=a-1;j>=0;--j)
        {
            if(array[j]%i==0)
            {
                if(mini>j)
                {
                    mini=j;
                }
                if(maxi<j)
                {
                    maxi=j;
                }
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
    cout<<((flag==false)?-1:maxi-mini)<<"\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}