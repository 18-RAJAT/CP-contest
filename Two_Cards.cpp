#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int x=0,y=-1;
    for(int i=1;i<n;++i)
    {
        if(a[i]>a[x])x=i;
    }
    for(int i=0;i<n;++i)
    {
        if(i==x)continue;
        if(y==-1 || a[i]>a[y])y=i;
    }
    int mx=max(a[x],b[x]);
    int ok=(~y)?max(a[y],b[y]):-1;
    bool f=false;
    for(int i=0;i<n;++i)
    {
        if(i==x)continue;
        if(max(a[i],b[i])>mx)
        {
            f=true;
            break;
        }
    }
    if(!f && ~y && mx>ok)f=true;
    cout<<(f?"Yes":"No")<<endl;
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