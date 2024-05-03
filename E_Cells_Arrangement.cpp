#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n-2;++i)
    {
        cout<<1<<" "<<i+1<<endl;
    }
    cout<<n-1<<" "<<1<<endl<<n<<" "<<n<<endl;
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