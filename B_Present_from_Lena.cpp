#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<=n*2;++i)
    {
        int separate=2*abs(n-i);
        for(int j=0;j<separate;++j)
        {
            cout<<" ";
        }
        for(int j=0;j<=n-abs(n-i);++j)
        {
            cout<<j;
            if(j<n-abs(n-i))cout<<" ";
        }
        for(int j=n-abs(n-i)-1;j>=0;--j)
        {
            cout<<" "<<j;
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}