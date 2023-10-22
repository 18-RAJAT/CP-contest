#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>zero;
    for(int i=n-1;i>=0;--i)
    {
        if(s[i]=='1')
        {
            continue;
        }
        if(zero.empty())
        {
            zero.push_back(i);
        }
        else
        {
            zero.push_back(zero.back()+i);
        }
    }
    int m=zero.size();
    vector<int>res(n,-1);
    auto check=[&](int n)->int
    {
        return 1LL*n*(n+1)/2;
    };
    for(int i=0;i<m;++i)
    {
        int cnt=check(n-1)-check(n-2-i);
        cnt-=zero[i];
        res[i]=cnt;
    }
    // for(int i=0;i<n;++i)
    // {
    //     if(s[i]=='1')
    //     {
    //         cout<<i+1<<" ";
    //     }
    // }
    for(int i=0;i<n;++i)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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