#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int inc=2*k;
    if(k==1)
    {
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
        cout<<n<<endl;
    }
    else if(n==inc)
    {
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        cout<<n-(k-1)<<" "<<1<<endl;
    }
    else if(n>inc)
    {
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        cout<<n-(k-1)<<" "<<1<<endl;
    }
    else if(n==inc-1)
    {
        cout<<"YES"<<endl;
        cout<<"2"<<endl;
        cout<<"2 1"<<endl;
    }
    else if(n==k)
    {
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
        cout<<"1"<<endl;
    }
    else cout<<"NO"<<endl;
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