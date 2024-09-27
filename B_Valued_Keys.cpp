#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string x,y;
    cin>>x>>y;
    string ans;
    for(int i=0;i<x.size();++i)
    {
        if(x[i]>=y[i])ans+=min(x[i],y[i]);
        else
        {
            cout<<-1;
            return;
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}