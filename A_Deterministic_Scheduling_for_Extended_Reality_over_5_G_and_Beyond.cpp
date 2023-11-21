#include<bits/stdc++.h>
using namespace std;
#define int long long

int log2(int x)
{
    int ans=0;
    while(x>1)
    {
        x/=2;
        ans++;
    }
    return ans;
}
int diagram(int n,int k,int t,int r,vector<vector<vector<double>>> &s0,vector<vector<vector<double>>> &d,vector<vector<vector<double>>> &p,vector<vector<int>> &t0,vector<int> &td,vector<int> &tbs)
{
    int ans=0;
    for(int j=0;j<n;++j)
    {
        int t1=t0[j]+td[j]-1;
        for(int i=t0[j];i<=t1;++i)
        {
            double g=0;
            for(int l=0;l<k;++l)
            {
                for(int m=0;m<r;++m)
                {
                    g+=p[l][m][i]*log2(1+s0[l][m][i]);
                }
            }
            if(g>=tbs[j])
            {
                ans++;
            }
        }
    }
    return ans;
}

void sol()
{
    int n,k,t,r;
    cin>>n>>k>>t>>r;
    vector<vector<vector<double>>> s0(k,vector<vector<double>>(r,vector<double>(t)));
    vector<vector<vector<double>>> d(k,vector<vector<double>>(n,vector<double>(n)));
    vector<vector<vector<double>>> p(k,vector<vector<double>>(r,vector<double>(t)));
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<r;++j)
        {
            for(int l=0;l<t;++l)
            {
                cin>>s0[i][j][l];
            }
        }
    }
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int l=0;l<n;++l)
            {
                cin>>d[i][j][l];
            }
        }
    }
    vector<int> t0(n),td(n),tbs(n);
    for(int i=0;i<n;++i)
    {
        cin>>tbs[i]>>t0[i]>>td[i];
    }
    int ans=0;
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<r;++j)
        {
            for(int l=0;l<t;++l)
            {
                cin>>p[i][j][l];
            }
        }
    }
    ans=diagram(n,k,t,r,s0,d,p,t0,td,tbs);
    cout<<ans<<endl;
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<r;++j)
        {
            for(int l=0;l<t;++l)
            {
                cout<<p[i][j][l]<<" ";
            }
            cout<<endl;
        }
    }
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