#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int>dp(n+1,0),ndp(n+1,0);
    for(int i=1;i<=n;++i)
    {
        dp[i]=dp[i-1]+(s[i-1]=='1');
        ndp[i]=ndp[i-1]+(s[i-1]=='2');
    }
    vector<int>pos;
    for(int i=1;i<=n;++i)
    {
        if(s[i-1]=='/')pos.push_back(i);
    }
    int m=pos.size();
    vector<int>a(m),b(m);
    for(int i=0;i<m;++i)
    {
        a[i]=dp[pos[i]-1];
        b[i]=ndp[pos[i]];
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int lb=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
        int rb=upper_bound(pos.begin(),pos.end(),r)-pos.begin();
        if(lb>=rb)
        {
            cout<<"0"<<endl;
            continue;
        }
        int c=dp[l-1],d=ndp[r];
        int mn=min(dp[r]-c,d);
        if(mn<0)mn=0;
        int low=0,high=mn,ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int L=lower_bound(a.begin()+lb,a.begin()+rb+1,c+mid)-a.begin();
            int U=upper_bound(b.begin()+lb,b.begin()+rb+1,d-mid)-b.begin()-1;
            (L<=U)?(ans=mid,low=mid+1):(high=mid-1);
        }
        if(ans>=0)
        {
            cout<<(ans==0?1:2*ans+1)<<endl;
        }
        else cout<<"0"<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}