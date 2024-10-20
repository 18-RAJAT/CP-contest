#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int m1;
    cin>>m1;
    for(int i=0;i<m1;++i)
    {
        int u,v;
        cin>>u>>v;
    }
    int m2;
    cin>>m2;
    for(int i=0;i<m2;++i)
    {
        int u,v;
        cin>>u>>v;
    }
    function<bool(int,int,vector<int>&,vector<int>&)>recur=[&](int n,int k,vector<int>&a,vector<int>&b)->bool
    {
        int out_1=0,in_1=0,out_2=0,in_2=0;
        for(int i=0;i<n;++i)
        {
            (a[i]==1)?out_1++:in_1++;
            (b[i]==1)?out_2++:in_2++;
        }
        return (out_1==in_2 && out_2==in_1);
    };
    if(!recur(n,k,a,b))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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