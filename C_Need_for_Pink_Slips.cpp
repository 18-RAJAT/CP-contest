#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    double c,m,p,v;//c,m,p are probabilities of cash,impound,pink slip respectively and v is volatility factor
    cin>>c>>m>>p>>v;
    double ans=0;
    double tmp=1e8;
    function<double(int,int,int,int)>dfs=[&](int c,int m,int p,int v)->double
    {
        double res=p/tmp;       
        if(c>0)
        {
            if(c<=v)
            {
                if(m>0)
                {
                    res+=c/tmp*(1+dfs(0,m+c/2,p+c/2,v));
                }
                else
                {
                    res+=c/tmp*(1+dfs(0,0,p+c,v));
                }
            }
            else
            {
                if(m>0)
                {
                    res+=c/tmp*(1+dfs(c-v,m+v/2,p+v/2,v));
                }
                else
                {
                    res+=c/tmp*(1+dfs(c-v,0,p+v,v));
                }
            }
        }
        return res;
    };
    int C=c*tmp;
    int M=m*tmp;
    int P=p*tmp;
    int V=v*tmp;
    // cout<<V<<" "<<C<<" "<<M<<" "<<P<<endl;
    cout<<fixed<<setprecision(12)<<dfs(C,M,P,V)<<endl;
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