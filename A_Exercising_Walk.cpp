#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int u,v,x1,x2,y1,y2;
    cin>>u>>v>>x1>>y1>>x2>>y2;
    u=u-a+b;
    v=v-c+d;
    if(u>=x1 && u<=x2 && v>=y1 && v<=y2)
    {
        (x1==x2 && a!=0) || (y1==y2 && c!=0) ? cout<<"No"<<endl : cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
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