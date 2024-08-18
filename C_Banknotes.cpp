#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),ans(n);
    for(int i=0;i<n;++i)cin>>a[i];
    k++;
    a.push_back(18);
    for(int i=0;i<n;++i)
    {
        int chk=a[i+1]-a[i],j,x=10;
        for(j=1;j<chk;++j)x*=10;x--;
        if(k<=x)
        {
            cout<<k;
            for(j=i-1;j>=0;--j)
            {
                cout<<ans[j];
            }
            cout<<endl;return;
        }
        else ans[i]=x,k-=x;
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