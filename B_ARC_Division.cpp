#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,r;
    cin>>n>>r;
    vector<array<int,2>>arr(n);
    for(int i=0;i<n;++i)cin>>arr[i][0]>>arr[i][1];
    for(int i=0;i<n;++i)
    {
        int d=arr[i][0],a=arr[i][1];
        if((d==1 && r>=1600 && r<=2799) || (d==2 && r>=1200 && r<=2399))r+=a;
    }
    cout<<r<<endl;
}
signed main()
{
    sol();
    return 0;
}