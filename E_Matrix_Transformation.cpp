#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cin>>a[i][j];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cin>>b[i][j];
    }
    int ans=1,f=0;
    for(int k=0;k<32;++k)
    {
        vector<int>l(n),r(m),L(n),R(m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j) ((b[i][j]/(1LL<<k))&1)?r[j]++:l[i]++;
        }
        int tmp1=n,tmp2=m;
        for(int i=0;i<n+m;++i)
        {
            f=0;
            for(int i=0;i<n;++i)if(!L[i] && l[i]==tmp2)L[i]=1,tmp1--,f=1;
            for(int i=0;i<m;++i)if(!R[i] && r[i]==tmp1)R[i]=1,tmp2--,f=1;
            if(!f)break;
        }
        for(int i=0;i<n;++i)
        {
            if(L[i])continue;
            for(int j=0;j<m;++j)
            {
                if(R[j])continue;
                if((a[i][j]>>k&1)^(b[i][j]>>k&1))
                {
                    ans=0;
                    break;
                }
            }
            if(!ans)break;
        }
        if(!ans)break;
    }
    cout<<((ans)?"Yes":"No")<<endl;
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