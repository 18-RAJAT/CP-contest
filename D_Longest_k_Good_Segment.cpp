#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>fz(1e6+5,0);
    int x=0,mx=0,l=0,r=0,cnt=0;
    for(int i=0;i<n;++i)
    {
        if(fz[a[i]]==0)cnt++;
        fz[a[i]]++;
        while(cnt>k)
        {
            fz[a[x]]--;
            if(fz[a[x]]==0)cnt--;
            x++;
        }
        int len=i-x+1;
        while(mx<len)mx=len,l=x,r=i;
    }
    cout<<l+1<<" "<<r+1;
}
signed main()
{
    sol();
    return 0;
}