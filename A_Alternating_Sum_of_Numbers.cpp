#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=1,s=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        (ans)?s+=x:s-=x;
        ans^=1;
    }
    cout<<s<<endl;
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