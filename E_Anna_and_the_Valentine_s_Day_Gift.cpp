#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    auto even_odd=[&](int p)->int
    {
        int cnt=0;
        while(p)
        {
            p/=10;
            cnt++;
        }
        return cnt;
    };
    auto trailing_zeroes=[&](int p)->int
    {
        int cnt=0;
        while(p%10==0)
        {
            p/=10;
            cnt++;
        }
        return cnt;
    };
    sort(array.begin(),array.end(),[&](int x,int y)->bool
    {
        return trailing_zeroes(x)<trailing_zeroes(y)?true:trailing_zeroes(x)==trailing_zeroes(y)?x<y:false;
    });
    int ans=0;
    for(int i=n-1;~i;--i)
    {
        ans+=even_odd(array[i]);
        int last=n-1;
        if(i%2==last%2)
        {
            ans-=trailing_zeroes(array[i]);
        }
    }
    cout<<(ans<=m?"Anna":"Sasha")<<endl;
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