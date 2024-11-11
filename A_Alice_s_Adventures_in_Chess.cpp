#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    vector<pair<int,int>>arr;
    arr.push_back({0,0});
    for(int i=0;i<n;++i)
    {
        int x=arr.back().first;
        int y=arr.back().second;
        if(s[i]=='N')y++;
        else if(s[i]=='S')y--;
        else if(s[i]=='E')x++;
        else x--;
        arr.push_back({x,y});
    }
    int dx=arr.back().first;
    int dy=arr.back().second;
    bool ok=false;
    for(int i=0;i<=1000 && !ok;++i)
    {
        for(int j=0;j<=n && !ok;++j)
        {
            int x=i*dx+arr[j].first;
            int y=i*dy+arr[j].second;
            if(x==a && y==b)ok=true;
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
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