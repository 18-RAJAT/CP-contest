#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>X(m);
    for(int i=0;i<m;++i)cin>>X[i];
    vector<int>A(m);
    for(int i=0;i<m;++i)cin>>A[i];
    vector<array<int,2>>show(m);
    for(int i=0;i<m;++i) show[i]={X[i],A[i]};
    sort(show.begin(),show.end());
    int ans=0;
    for(int i=0;i<m;++i)ans+=show[i][1];
    if(ans!=n)
    {
        cout<<"-1"<<endl;
        return;
    }
    int ptr=1,Res=0;
    for(int i=0;i<m;++i)
    {
        int x=show[i][0],a=show[i][1];
        int s=max(ptr,x);
        if(s>n)
        {
            cout<<"-1"<<endl;
            return;
        }
        int t=min(n,s+a-1),k=t-s+1;
        if(k<a)
        {
            cout<<"-1"<<endl;
            return;
        }
        int ops=k*(s-x)+(k*(k-1))/2;
        Res+=ops;
        ptr=t+1;
    }
    if(ptr<=n)
    {
        cout<<"-1"<<endl;
        return;
    }
    cout<<Res<<endl;
}
signed main()
{
    sol();
    return 0;
}