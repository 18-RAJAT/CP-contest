#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0,count=0;
    map<int,int>mp;
    mp.clear();
    for(int i=0;i<n;++i)
    {
        char ch;
        cin>>ch;
        int x;
        cin>>x;
        if(ch=='-')
        {
            mp[x]==1?count--:ans++,mp[x]=0;
        }
        else if(ch=='+')
        {
            mp[x]==0?count++,mp[x]=1:mp[x]=1;
        }
        ans=max<int>(ans,count);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}