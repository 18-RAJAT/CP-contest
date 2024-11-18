#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n<5)
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<=n;i+=2)
    {
        if(i!=5)cout<<i<<" ";
    }
    cout<<"5 4 ";
    for(int i=2;i<=n;i+=2)
    {
        if(i!=4)cout<<i<<" ";
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