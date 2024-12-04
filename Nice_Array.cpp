#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int s=0,m=0;
    for(int i=0;i<n;++i)
    {
        int F=a[i],f;
        bool ok=0;
        if(F>=0)
        {
            f=F/k;
            if(F%k!=0)
            {
                ok=1,m++;
            }
        }
        else
        {
            if(F%k==0)f=F/k;
            else
            {
                f=F/k-1;
                ok=1,m++;
            }
        }
        s+=f;
    }
    int y=-s;
    if(y>=0 && y<=m)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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