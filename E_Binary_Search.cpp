#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n+1),pos(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int left=1,right=n+1;
    while(left+1<right)
    {
        int mid=(left+right)>>1;
        (a[mid]<=x)?left=mid:right=mid;
    }
    if(left==pos[x])
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<1<<endl;
        cout<<pos[x]<<" "<<left<<endl;
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