#include<bits/stdc++.h>
using namespace std;
#define int long long
int cost(vector<int> &a,vector<int> &b,int n)
{
    int A=*min_element(a.begin(),a.end());
    int B=*min_element(b.begin(),b.end());
    int cost=min(A*n+accumulate(b.begin(),b.end(),0LL),B*n+accumulate(a.begin(),a.end(),0LL));
    return cost;
}
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int ans=cost(a,b,n);
    cout<<ans<<"\n";
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