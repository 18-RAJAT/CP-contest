#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    vector<array<int,2>>ans;
    if(k&1)ans.push_back({x,y});k--;
    for(int i=1;i<=k;i+=2)
    {
        ans.push_back({x+i,y+i});
        ans.push_back({x-i,y-i});
    }
    for(auto& it:ans)cout<<it[0]<<" "<<it[1]<<endl;
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