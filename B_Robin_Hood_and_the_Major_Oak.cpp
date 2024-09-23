#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int TotalLeaves=n-k,LeavesLost;
    LeavesLost=(n+1)>>1,LeavesLost-=(TotalLeaves+1)>>1;
    cout<<(LeavesLost%2==0?"YES":"NO")<<endl;
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