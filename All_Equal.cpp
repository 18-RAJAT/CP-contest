#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAX=500005,MOD=998244353;

//Rajat joshi template
int power(int a,int b,int m)
{
    int res=1;
    a%=m;
    while(b)
    {
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
void sol()
{
    static vector<int>res(MAX,1),Spf(MAX,1);
    static vector<vector<int>>D(MAX);
    static bool ok=false;
    if(!ok)
    {
        Spf[0]=Spf[1]=0;
        for(int i=2;i<MAX;++i)
        {
            if(Spf[i])
            {
                for(int j=i;j<MAX;j+=i)res[j]=-res[j],Spf[j]=0;
                int sq=i*i;
                for(int j=sq;j<MAX;j+=sq)res[j]=0;
            }
        }
        for(int i=1;i<MAX;++i)
        {
            for(int j=i;j<MAX;j+=i)
            {
                D[j].push_back(i);
            }
        }
        ok=true;
    }
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int j=1;j<=m;++j)
    {
        int q=m/j;
        vector<int>sum(q+1,0);
        for(int i=1;i<=q;++i)
        {
            for(auto& it:D[i])
            {
                sum[i]+=(int)res[it]*(q/it);
            }
            sum[i]=(sum[i]+MOD)%MOD;
        }
        for(int i=1;i<=q;++i)
        {
            ans=(ans+power(sum[i],n,MOD))%MOD;
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