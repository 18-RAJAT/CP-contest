#include<bits/stdc++.h>
using namespace std;
#define int long long
int Binary_Search_Custom(vector<int>&arr,int x)
{
    int left=0,right=arr.size();
    while(left<right)
    {
        int mid=left+(right-left)/2;
        (arr[mid]<x)?left=mid+1:right=mid;
    }
    return left;
}
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>interval(n);
    for(auto it=interval.begin();it!=interval.end();++it)
    {
        cin>>it->first>>it->second;
    }
    sort(interval.begin(),interval.end(),[&](pair<int,int>&a,pair<int,int>&b)->bool
    {
        if(a.first!=b.first)return a.first<b.first;
        return a.second>b.second;
    });
    vector<int>dp,ndp;
    for(auto it=interval.begin();it!=interval.end();++it)
    {
        dp.push_back(it->second);
    }
    for(auto it=dp.begin();it!=dp.end();++it)
    {
        int ans=Binary_Search_Custom(ndp,*it);
        if(ans==ndp.size())ndp.push_back(*it);
        else ndp[ans]=*it;
    }
    // for(auto it=ndp.begin();it!=ndp.end();++it)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    cout<<ndp.size()<<endl; 
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