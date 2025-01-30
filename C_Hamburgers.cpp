#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n[3],p[3],c[3],r;
    cin>>n[0]>>n[1]>>n[2];
    cin>>p[0]>>p[1]>>p[2];
    cin>>r;
    string st="BSC";
    for(int i=0;i<3;++i)c[i]=count(s.begin(),s.end(),st[i]);
    int left=0,right=1e14,ans;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int cost=0;
        for(int i=0;i<3;++i)cost+=max<int>(mid*c[i]-n[i],0)*p[i];
        (cost<=r)?ans=mid,left=mid+1:right=mid-1;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}