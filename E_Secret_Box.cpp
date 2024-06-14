#include<bits/stdc++.h>
using namespace std;
#define int long long
 
template<typename T1,typename T2>bool c_max(T1& a,T2 b){return a<b?a=b,true:false;}
void sol()
{
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    int ans=0;
    for(int i=1;i<=x;++i)
    {
        if(k%i==0)
        {
            for(int j=1;j<=y;++j)
            {
                if((k/i)%j==0)
                {
                    int temp=k/i/j;
                    if(z<temp)continue;
                    c_max(ans,(x-i+1)*(y-j+1)*(z-temp+1));
                }
            }
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