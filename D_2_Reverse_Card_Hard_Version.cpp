#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=2;i<=sqrt(2*max(n,m));++i)
    {
        for(int j=1;j<i;++j)
        {
            int card=i-j;
            if(gcd(i,card)!=1)
            {
                continue;
            }
            int maximize=min(n/j,m/card);
            // for(auto k:{j,card})
            // {
            //     if(k==1)
            //     {
            //         continue;
            //     }
            //     int temp=min(n/k,m/k);
            //     maximize=max(maximize,temp);
            // }
            // int temp=(maximize*(maximize+1))/2;
            // ans+=temp;
            ans+=maximize/i;//+gcd(maximize,i-j);
        }
    }
    cout<<ans<<endl;
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