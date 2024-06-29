#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n);
    int i=0;
    for(;i<n;++i)
    {
        cin>>a[i][0];
    }
    i=0;
    for(;i<n;++i)
    {
        cin>>a[i][1];
    }
    i=0;
    int l=0,r=0,ans1=0;
    for(;i<n;++i)
    {
        int x=a[i][0],y=a[i][1];
        if(x>y){l+=x;continue;}
        if(x<y){r+=y;continue;}
        if(x==1){ans1++;continue;}
        if(x==-1){ans1++,l--,r--;continue;}
    }
    if(r<l)swap(l,r);
    int mini=min(r-l,ans1);
    l+=mini,ans1-=mini;
    cout<<((l!=r)?l:l+ans1/2)<<endl;
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