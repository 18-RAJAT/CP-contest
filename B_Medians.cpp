#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int lower=k-1,greater=n-k;
    if(lower==0||greater==0)
    {
        if(n==1) cout<<1<<endl<<1<<endl;
        else cout<<-1<<endl;
    }
    else
    {
        if(lower&1) cout<<3<<endl<<1<<" "<<k<<" "<<k+1<<endl;
        else cout<<3<<endl<<1<<" "<<k-1<<" "<<k+2<<endl;
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