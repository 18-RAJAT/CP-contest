#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    vector<int>check(n,0);
    for(int i=n-1;i>=1;--i)
    {
        int tmp=a[i];
        while(tmp<a[i-1])
        {
            tmp*=2;
            ++check[i];
        }
        tmp=a[i-1];
        while(tmp<=a[i])
        {
            tmp*=2;
            --check[i];
        }
        if(check[i]<0)
        {
            check[i]++;
        }
    }
    for(int i=1;i<n;++i)
    {
        check[i]=max<int>(0LL,check[i-1]+check[i]);
    }
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=check[i];
    }
    cout<<sum<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}