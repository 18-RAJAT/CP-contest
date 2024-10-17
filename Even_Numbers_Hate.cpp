#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int odd=0,even=0;
    for(int i=0;i<n;++i)
    {
        (a[i]&1)?odd++:even++;
    }
    cout<<((odd==0)?0:even+1+(odd-1)/2)<<endl;
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