#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n*m);
    for(int i=0;i<n*m;++i)
    {
        cin>>a[i];
    }
    if(n*m==1){cout<<"-1"<<endl;return;}
    int tmp=n*m;
    for(int i=0;i<n*m;++i)
    {
        cout<<a[(i+1)%tmp]<<" ";
        if((i+1)%n==0)
        {
            cout<<endl;
        }
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