#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int l=0,r=0,u=0,d=0;
    for(auto& ch:s)
    {
        l+=(ch=='L'),r+=(ch=='R'),u+=(ch=='U'),d+=(ch=='D');
    }
    l=r=min(l,r),u=d=min(u,d);
    if(l==0 && r==0 && u>=1)u=d=1;
    else if(u==0 && d==0 && l>=1)l=r=1;
    cout<<(l+r+u+d)<<endl;
    for(int i=0;i<u;++i)cout<<"U";
    for(int i=0;i<l;++i)cout<<"L";
    for(int i=0;i<d;++i)cout<<"D";
    for(int i=0;i<r;++i)cout<<"R";cout<<endl;
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