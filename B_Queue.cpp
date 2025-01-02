#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5;
void sol()
{
    int n;
    cin>>n;
    int a[N]={0},b[N]={0};
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        b[x]=y;
        ++a[x],--a[y];
    }
    int ans=1,k;
    while(a[ans]!=1)++ans;
    k=b[0];
    while(ans && k)
    {
        cout<<ans<<" "<<k<<" ";
        ans=b[ans];
        k=b[k];
    }
    if(ans)cout<<ans;
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}