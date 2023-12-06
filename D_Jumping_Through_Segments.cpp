#include<bits/stdc++.h>
using namespace std;
#define int long long
bool jump_segment(int mid,vector<pair<int,int>>& segments)
{
    int n=segments.size();
    int maximum=0,minimum=0;
    for(int i=0;i<n;++i)
    {
        maximum=min(segments[i].second,maximum+mid);
        minimum=max(segments[i].first,minimum-mid);
        if(maximum<minimum)
        {
            return false;
        }
    }
    return true;
}
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>segments;
    for(int i=0;i<n;++i)
    {
        int l,r;
        cin>>l>>r;
        segments.push_back(make_pair(l,r));
    }
    int low=0,high=1e9;
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(jump_segment(mid,segments))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans<<endl;
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