#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int ans=0;
    vector<int>win;
    for(int i=0;i<n;++i)
    {
        if(a[i]>b[i])ans++;
        else win.push_back(b[i]-a[i]+1);
    }
    int res=(n/2)+1;
    if(ans>=res)
    {
        cout<<"YES"<<endl;
        return;
    }
    sort(win.begin(),win.end());
    for(auto& it:win)
    {
        if(x>=it)x-=it,ans++;
        else break;
    }
    cout<<(ans>=res?"YES":"NO")<<endl;
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