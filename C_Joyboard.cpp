#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k==1)
    {
        cout<<1<<"\n";
        return;
    }
    if(k>3)
    {
        cout<<0<<"\n";
        return;
    }
    int calc=min(n,m);
    if(n<m)
    {
        calc+=m/n-1;
    }
    if(k==3)
    {
        calc-=m;
    }
    cout<<abs(calc)<<"\n";
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