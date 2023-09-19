#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
void sol()
{
    int n,m;
    cin>>n>>m;
    int x=0,y=0;
    int ok=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        x^=a[i];
    }
    for(int i=0;i<m;++i)
    {
        int p;
        cin>>p;
        ok|=p;
    }
    for(int i=0;i<n;++i)
    {
        // if((x^a[i])<=y)
        // {
        //     ok=1;
        //     break;
        // }
        y^=(a[i]|ok);
    }
    cout<<min(x,ok)<<" "<<max(x,ok)<<"\n";
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