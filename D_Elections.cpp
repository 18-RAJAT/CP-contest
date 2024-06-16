#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
void sol()
{
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0,candidate=0;
    a[0]+=c;
    for(int i=0;i<n;++i)
    {
        if(ans<a[i])ans=a[i],candidate=i;
    }
    for(int i=0;i<n;++i)
    {
        if(candidate==i)cout<<0<<" ";
        else
        {
            if(ans<=a[i])cout<<i<<" ";
            else cout<<i+1<<" ";
        }
        if(i+1<n)a[i+1]+=a[i];
    }
    cout<<endl;
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