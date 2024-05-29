#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,t,u,v;
    cin>>n>>t;
    int count=0;
    vector<int>a(n+1);
    for(int i=0;i<n-1;++i)
    {
        cin>>u>>v;
        a[v]=u;
    }
    int x;
    cin>>x;
    while(a[x]!=0)
    {
        x=a[x],count++;
    }
    cout<<(((count&1) || (n-count-1)&1)?"Ron":"Hermione");
}
signed main()
{
    sol();
    return 0;
}