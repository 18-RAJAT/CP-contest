#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>array(n);
    unordered_map<int,unordered_map<int,int>>mp;
    // mp.reserve(x);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
        mp[array[i]%x][array[i]%y]++;
    }
    int total=0;
    for(int i=0;i<n;++i)
    {
        total+=mp[(x-(array[i]%x))%x][array[i]%y]-(array[i]%x==(x-(array[i]%x))%x);
    }
    cout<<total/2<<endl;
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