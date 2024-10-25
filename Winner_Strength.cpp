#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n-1;++i)
    {
        if(a[1]<=a[0])
        {
            a[0]+=a[1];
            a.erase(a.begin()+1);
        }
        else
        {
            a[1]+=a[0];
            a.erase(a.begin());
        }
    }
    cout<<a[0]<<endl;
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