#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return;
    }
    int op=0;
    while(n)
    {
        op+=n%k;
        n/=k;
    }
    cout<<op<<endl;
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