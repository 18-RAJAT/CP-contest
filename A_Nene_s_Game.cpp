#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k,q;
    cin>>k>>q;
    array<int,2>a[k];
    int n;
    for(int i=0;i<k;++i)
    {
        cin>>a[i][0];
    }
    while(q--)
    {
        cin>>n;
        ((a[0][0]<=n)?cout<<a[0][0]-1<<" ":cout<<n<<" ");
    }
    cout<<endl;
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