#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>ans;
    map<int,int>mp;
    int lsb=1<<n;
    for(int i=0;i<lsb;++i)
    {
        if(!mp.count(i))
        {
            mp[i^x]=1;
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;++i)
    {
        cout<<(ans[i]^ans[i+1])<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}