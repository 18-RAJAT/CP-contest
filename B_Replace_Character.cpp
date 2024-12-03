#include<bits/stdc++.h>
using namespace std;
#define int long long
int F[11];
void Fact()
{
    F[0]=1;
    for(int i=1;i<=10;++i)F[i]=F[i-1]*i;
}
int permute(const vector<int>&cnt,int n)
{
    int ans=1;
    for(auto it:cnt)ans*=F[it];
    return F[n]/ans;
}
void sol()
{
    Fact();
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mn=LLONG_MAX;
    string ans=s;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            string tmp=s;
            tmp[i]=s[j];
            vector<int>cnt(26,0);
            for(auto c:tmp)++cnt[c-'a'];
            int res=permute(cnt,n);
            if(res<mn)
            {
                mn=res;
                ans=tmp;
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