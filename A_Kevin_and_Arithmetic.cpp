#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int e=0,o=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        (a[i]&1)?o++:e++;
    }
    if(e>=1)cout<<o+1<<endl;
    else cout<<((n>=2)?(n-1):0)<<endl;
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