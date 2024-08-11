#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    int p=x*k,q=y*k;
    for(int i=0;i<k-1;++i)
    {
        cout<<i+1<<" "<<i+1<<endl;
        p-=i+1,q-=i+1;
    }
    cout<<p<<" "<<q<<endl;
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