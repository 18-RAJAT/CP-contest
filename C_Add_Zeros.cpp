#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(i>=2)
        {
            int neg=i-1,pos=neg+x;
            mp[pos].push_back(neg);
        }
    }
    map<int,int>check;
    queue<int>q;
    q.push(n);
    int ans=n;
    check[n]=1;
    while(!q.empty())
    {
        int f=q.front();
        ans=max(ans,f);
        q.pop();
        for(auto& x:mp[f])
        {
            if(!check[x+f])
            {
                q.push(x+f);
                check[x+f]=1;
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