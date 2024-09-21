#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    int blend=min(x,y);
    cout<<(n+blend-1)/blend<<endl;    
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