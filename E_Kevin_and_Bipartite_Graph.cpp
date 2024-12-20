#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int N=n*2;
    if(N<=m)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<((i+j)%N/2+1)<<" ";
        }
        cout<<endl;
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