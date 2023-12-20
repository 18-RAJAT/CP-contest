#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    // vector<int>order;
    // for(int i=1;i<=n;i++)
    // {
    //     order.push_back(i);
    // }
    // for(int i=1;i<n;i++)
    // {
    //     if(k==0)
    //     {
    //         break;
    //     }
    //     swap(order[i],order[i-1]);
    //     k--;
    // }
    // for(auto i:order)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<endl; 
    int tmp=n-k;
    for(int i=tmp;i<=n;++i)
    {
        cout<<i<<" ";
    }
    int tmp1=tmp-1;
    for(int i=tmp1;i>=1;--i)
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