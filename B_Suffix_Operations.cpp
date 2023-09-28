#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    /*
        Approach:
        To calculate the total cost, we need to find the difference between adjacent elements.
        Then we need to find the maximum difference between adjacent elements.
        Then we need to subtract the maximum difference from the total cost.
        Because we need to find the minimum cost.
    */
    int diff[n],tot=0;
    for(int i=1;i<n;++i)
    {
        diff[i-1]=abs(a[i]-a[i-1]);
        tot+=diff[i-1];
    }
    int maxi=max(diff[0],diff[n-2]);
    for(int i=1;i<n-1;++i)
    {
        maxi=max(maxi,diff[i]+diff[i-1]-abs(a[i+1]-a[i-1]));
    }
    cout<<tot-maxi<<endl;
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