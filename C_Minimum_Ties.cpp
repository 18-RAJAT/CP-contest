#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(2*(j-i)==n)cout<<0<<" ";
            if(2*(j-i)<n)cout<<1<<" ";
            if(2*(j-i)>n)cout<<-1<<" ";
        }
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