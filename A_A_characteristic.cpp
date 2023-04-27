#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol()
{
    ll n,k;
    cin>>n>>k;
    ll temp=(n*(n-1))/2;
    ll count=-1;

    for(int i=0;i<=n;++i)
    {
        ll resv=n-i;
        // if((i*(i-1))/2+())

        if(i*i-i+resv*(resv)-(resv)==k*2)
        {
            cout<<"YES"<<"\n";
            for(int j=0;j<i;++j)
            {
                cout<<"-1"<<" ";
            }
            // for(int j=0;j<resv;++j)
            // {
            //     cout<<"1"<<" ";
            // }
            for(int j=0;j<n-i;++j)
            {
                cout<<"1"<<" ";
            }
            cout<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}