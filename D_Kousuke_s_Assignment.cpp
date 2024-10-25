#include<bits/stdc++.h>
using namespace std;
#define int long long
int segment(vector<int>&a,int n)
{
    unordered_map<int,int>mp;
    int ans=0,sum=0;
    mp[sum]=1;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        if(mp[sum])
        {
            mp.clear(),sum=0,ans++;
        }
        mp[sum]=1;
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    cout<<segment(a,n)<<endl;
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