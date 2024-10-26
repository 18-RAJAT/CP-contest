#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int w=0,h=0;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        w=max(w,x);
        h=max(h,y);
    }
    cout<<2*(w+h)<<endl;
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