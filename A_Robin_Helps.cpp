#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int RobinGold=0,GaveGold=0;
    for(int i=0;i<n;++i)
    {
        if(k<=a[i])RobinGold+=a[i];
        else if(a[i]==0 && RobinGold>=1)
        {
            RobinGold--,GaveGold++;
        }
    }
    cout<<GaveGold<<endl;
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