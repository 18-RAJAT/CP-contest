#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int OX=0,OY=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        i<n/2?OX+=a[i]:OY+=a[i];
    }
    cout<<(OX*OX+OY*OY);
}
signed main()
{
    sol();
    return 0;
}