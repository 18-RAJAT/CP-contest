#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    vector<vector<int>>pref(n+1,vector<int>(26,0)),suf(n+1,vector<int>(26,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<26;++j)
        {
            pref[i+1][j]=pref[i][j],suf[i+1][j]=suf[i][j];
        }
        pref[i+1][a[i]-'a']++,suf[i+1][b[i]-'a']++;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        int ans=1;
        for(int i=0;i<26;++i)
        {
            ans+=abs((pref[r+1][i]-pref[l][i])-(suf[r+1][i]-suf[l][i]));
        }
        cout<<(ans-1)/2<<endl;
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