#include<bits/stdc++.h>
using namespace std;
void sol()
{
    long long n;
    cin>>n;
    vector<long long>a(n);
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    bool flag=false;
    long long sum=0,mx=INT_MIN;
    for(long long i=0;i<n;++i)
    {
        sum+=a[i];
        mx=max<long long>(mx,a[i]);
        if(sum>mx)
        {
            flag=true;
            break;
        }
        if(sum<=0)
        {
            sum=0;
            mx=INT_MIN;
        }
        flag;
    }
    sum=0,mx=INT_MIN;
    for(long long i=n-1;i>=0;--i)
    {
        sum+=a[i];
        mx=max<long long>(mx,a[i]);
        if(sum>mx)
        {
            flag=true;
            break;
        }
        if(sum<=0)
        {
            sum=0;
            mx=INT_MIN;
        }
        flag;
    }
    cout<<(flag?"NO\n":"YES\n");
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