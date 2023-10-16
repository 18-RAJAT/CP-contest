#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int c,m,p,v;//c,m,p are probabilities of cash,impound,pink slip respectively and v is volatility factor
    cin>>c>>m>>p>>v;
    function<double(int,int,int,int)> dfs=[&](int c,int m,int p,int v)->double
    {
        double res=p/100.0;
        if(c>0)
        {
            if(c<=v)
            {
                if(m>0)
                {
                    res+=c/100.0*(1+dfs(0,m+c/2,p+c/2,v));
                }
                else
                {
                    res+=c/100.0*(1+dfs(0,0,p+c,v));
                }
            }
            else
            {
                if(m>0)
                {
                    res+=c/100.0*(1+dfs(c-v,m+v/2,p+v/2,v));
                }
                else
                {
                    res+=c/100.0*(1+dfs(c-v,0,p+v,v));
                }
            }
        }
        if(m>0)
        {
            if(m<=v)
            {
                if(c>0)
                {
                    res+=m/100.0*(1+dfs(c+m/2,0,p+m/2,v));
                }
                else
                {
                    res+=m/100.0*(1+dfs(0,0,p+m,v));
                }
            }
            else
            {
                if(c>0)
                {
                    res+=m/100.0*(1+dfs(c+v/2,m-v,p+v/2,v));
                }
                else
                {
                    res+=m/100.0*(1+dfs(0,m-v,p+v,v));
                }
            }
        }
        return res;
    };
    cout<<fixed<<setprecision(12)<<dfs(c,m,p,v)<<'\n';
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