#include<bits/stdc++.h>
using namespace std;
 
void sol()
{
    // red=++ and blue=--
    // largest min use algo binary search
    // if(arr[i]<=mid)vals++;

    // case=vals>=k ans=mid and low=mid+1  else or high=mid-1
    auto largestMin=[&](long long int mid,long long int k,vector<long long int>&arr)->bool
    {
        long long int ans=0;
        bool vis=false;
        for(long long int i=0;i<arr.size() and k;++i)
        {
            // if(mid-arr[i]>=k)
            // {
            //     return false;
            // }
            if(mid-arr[i]>k)
            {
                return false;
            }
            if(arr[i]>=mid)
            {
                vis=true;
            }
            ans+=max<long long int>(0ll,k-(mid-arr[i]));
            ans+=max<long long int>(0ll,arr[i]-mid);
            k--;
        }
        if(not vis)
        {
            if(k&1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        long long int clr=2*ans;
        assert(1+clr>=k);
        return true;
    };
    long long int n,q;
    cin>>n>>q;
    vector<long long int>arr(n);
    for(long long int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    while(q--)
    {
        long long int k;
        cin>>k;

        long long int low=1,high=1e9;
        long long int mid=0;
        long long int ans=-1;

        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(largestMin(mid,k,arr))
            {
                ans=mid;
                low=mid+1;//r
            }
            else
            {
                high=mid-1;//b
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main()
{
    sol();
    return 0;
}