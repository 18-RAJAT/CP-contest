#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    if(n<2*k+1)
    {
        cout<<"-1\n";
        return;
    }
    int a[n];
    for(int i=0;i<n;++i)
    {
        a[i]=i+1;
    }
    int i=1;
    cout<<a[0]<<" ";
    while(k--)
    {
        swap(a[i],a[i+1]);
        cout<<a[i]<<" "<<a[i+1]<<" ";
        i+=2;//for next pair
    }
    for(int j=i;j<n;++j)//for remaining elements
    {
        cout<<a[j]<<" ";
    }
    cout<<'\n';
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