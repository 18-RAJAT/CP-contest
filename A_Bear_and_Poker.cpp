#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)
    {
        while(a[i]%2==0)a[i]/=2;
        while(a[i]%3==0)a[i]/=3;
    }
    sort(a.begin(),a.end());
    cout<<((a[0]==a[n-1])?"Yes":"No");
}
signed main()
{
    sol();
    return 0;
}