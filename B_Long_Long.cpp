#include<bits/stdc++.h>
using namespace std;
void sol()
{
    long long n;cin>>n;
    long long count(0),sum(0),temp(0),arr[n];
    for(long long i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    for(long long i=0;i<n;++i)
    {
        sum+=abs(arr[i]);
    }
    for(long long i=0;i<n;++i)
    {
        if(arr[i]>0)
        {
            if(temp)
            {
                count++;
            }
            temp=0;
        }
        else if(arr[i]<0)
        {
            temp++;
        }
    }
    if(temp)
    {
        count++;
    }
    cout<<sum<<" "<<count<<"\n";
}
int main()
{
    long long t;cin>>t;
    while(t--)
    {
        sol();
    }
}