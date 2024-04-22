#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int parity=n-k+1;
    int value=n-(2*(k-1));

    if(value>=1 && ~value&1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;++i)
        {
            cout<<2<<" ";
        }
        cout<<value<<endl;
    }
    else if(parity>=1 && parity&1)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;++i)
        {
            cout<<1<<" ";
        }
        cout<<parity<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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