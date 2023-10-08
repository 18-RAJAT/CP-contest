#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,pair<int,int>>,int>dp;
int recur(int index,vector<int>&itr,int water,int fire)
{
    if(water<0||fire<0)
    {
        return INT_MIN;
    }
    if(index==itr.size())
    {
        return 0;
    }
    int &res=dp[{index,{water,fire}}];//memoization
    if(res)
    {
        return res;
    }
    //recursion by taking and not taking the current element (itr[index]).
    int res1=recur(index+1,itr,water-itr[index],fire)+1;
    int res2=recur(index+1,itr,water,fire-itr[index])+1;
    res=max(res1,res2);
    return res=dp[{index,{water,fire}}];//caching

    assert(res>=0 && res<=itr.size());
}
bool can(int mid,vector<int>&itr,int water,int fire)
{
    dp.clear();
    //check if we can make mid number of elements equal to water and fire.
    int check=recur(0,itr,water*mid,fire*mid);
    if(check==itr.size())
    {
        return true;
    }
    return false;
}
//monotonic search space
int binarySearch(vector<int>&itr,int water,int fire)
{
    int left=0,right=1e6+1;
    int res=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(can(mid,itr,water,fire))
        {
            res=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return res;
}
void sol()
{
    int water,fire;
    cin>>water>>fire;
    int n;
    cin>>n;
    vector<int>itr(n);
    for(auto &val:itr)
    {
        cin>>val;
    }
    sort(itr.begin(),itr.end());
    reverse(itr.begin(),itr.end());
    cout<<binarySearch(itr,water,fire)<<endl;
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