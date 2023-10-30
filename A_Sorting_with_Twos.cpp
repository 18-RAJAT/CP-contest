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
    // sort(a.begin(),a.end());
    for(int i=1;i<n;++i)
    {
        int d=a[i]-a[i-1];
        if(d<0)
        {
            if((i&-i)!=i)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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