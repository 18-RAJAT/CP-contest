#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k;
    cin>>k;
    vector<vector<int>>parent(k);
    for(int i=0;i<k;++i)
    {
        int x;
        cin>>x;
        parent[i].resize(x);
        for(int j=1;j<x;++j)
        {
            cin>>parent[i][j];
            parent[i][j]--;
        }
    }
    int ans=0;
    for(int i=23;~i;--i)
    {
        int count=0;
        for(int j=0;j<k;++j)
        {
            if((1<<i) & parent[j].size())count++;
        }
        ans|=((count>=2)*((1<<(i+1))-1)|((count==1)*(1<<i)));
        if(count>=2)break;
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