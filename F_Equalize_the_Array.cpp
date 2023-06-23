#include<bits/stdc++.h>
using namespace std;
const long long N=100005;
void sol()
{
    long long n=0,cnt=1;
    cin>>n;
    array<long long,N>arr,c;
    for(long long i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.begin()+n);
    long long size=0;
    for(long long i=1;i<n;++i)
    {
        if(arr[i]==arr[i-1])
        {
            cnt++;
        }
        else
        {
            c[size]=cnt;
            cnt=1;
            size++;
        }
    }
    c[size]=cnt;
    size++;
    sort(c.begin(),c.begin()+size);
    long long ans=(long long)(1e18);
    long long i=size;
    for(long long j=0;j<size;++j)
    {
        ans=min<long long>(ans,n-c[j]*i);
        i--;

    }
    cout<<ans<<"\n";
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}