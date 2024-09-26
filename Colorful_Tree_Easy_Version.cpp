#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,vector<int>>Tree;
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    int Possible=0;
    for(map<int,vector<int>>::iterator it=Tree.begin();it!=Tree.end();++it)
    {
        if(it->second.size()==1)Possible++;
    }
    cout<<2*(n-Possible)+3*Possible<<endl;
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