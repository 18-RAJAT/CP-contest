#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    int j=1;
    if(x==0)
    {
        for(int i=1;i<n+1;++i)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(n==x || n==x+1)
    {
        cout<<"-1"<<endl;
        return;
    }
    int ert=x+1;
    for(int i=1;i<n-ert;++i)
    {
        j++;
        cout<<i<<" ";
    }
    cout<<n<<" ";
    for(int i=j;i<n;++i)
    {
        cout<<i<<" ";
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