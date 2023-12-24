#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int k=2;
    while(k<=1e18)
    {
        int chk=a[0]%k;
        for(int i=1;i<n;++i)
        {
            if(a[i]%k!=chk)
            {
                cout<<k<<"\n";
                return;
            }
        }
        k*=2;
    }
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