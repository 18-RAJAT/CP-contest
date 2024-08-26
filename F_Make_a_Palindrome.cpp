#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int combination=(n*(n+1)*(n+2))/6;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    map<int,int>pref;
    for(int i=0;i<n;++i)
    {
        int sum=0;
        for(int j=i;j>=0;--j)
        {
            sum+=a[j];
            combination-=pref[sum]++;
        }
        combination-=i+1;
    }
    cout<<combination<<endl;
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