#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    int i=k-1,j=k-1,ans=0;
    while(i>=0 || j<n)
    {
        if(i>=0 && j<n)
        {
            if(a[i]==a[j] && a[i]==1 && i==j)ans++;
            else if(a[i]==a[j] && a[i]==1)ans+=2;
            i--,j++;
        }
        else if(i<0 && j<n)
        {
            if(a[j]==1)ans++;
            i--,j++;
        }
        else if(i>=0 && j>=n)
        {
            if(a[i]==1)ans++;
            i--,j++;
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}