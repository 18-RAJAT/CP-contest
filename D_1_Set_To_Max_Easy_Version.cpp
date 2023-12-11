#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<pair<int,int>>pairs(n);
    for(int i=0;i<n;++i)
    {
        pairs[i]=make_pair(a[i],i);
    }
    sort(pairs.begin(),pairs.end());
    for(auto& it:pairs)
    {
        int left=it.second-1;
        int right=it.second+1;
        while(left>=0 && a[left]<=it.first && it.first<=b[left])
        {
            a[left]=it.first;
            left--;
        }
        while(right<n && a[right]<=it.first && it.first<=b[right])
        {
            a[right]=it.first;
            right++;
        }
    }
    cout<<((a==b)?"YES":"NO")<<endl;
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