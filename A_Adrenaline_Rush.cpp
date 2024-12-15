#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>f(n);
    for(int i=0;i<n;++i)cin>>f[i];
    vector<int> arr(n);
    for(int i=0;i<n;++i)arr[i]=i+1;
    unordered_map<int,int>init;
    for(int i=0;i<n;++i)
    {
        init[arr[i]]=i;
    }
    vector<int>vals=arr;
    unordered_map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[vals[i]]=i;
    }
    vector<pair<int,int>>vp;
    for(int i=n-1;~i;--i)
    {
        int ert=f[i];
        int pos=mp[ert];
        while(pos<i)
        {
            int nxt=pos+1;
            int tmp=vals[nxt];
            vp.emplace_back(tmp,ert);
            swap(vals[pos],vals[nxt]);
            mp[ert]=nxt;
            mp[tmp]=pos;
            pos++;
        }
    }
    for(int i=0;i<n-1;++i)
    {
        int x=f[i];
        int y=f[i+1];
        if(init[x]<init[y])
        {
            vp.emplace_back(y,x);
            vp.emplace_back(x,y);
        }
    }
    cout<<vp.size()<<endl;
    for(auto& it:vp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}