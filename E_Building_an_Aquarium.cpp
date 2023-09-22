#include<bits/stdc++.h>
using namespace std;
#define int long long
//bs on ans
int tank(vector<int>&arr,int h)
{
    int cap=0;
    for(int i=0;i<arr.size();++i)
    {
        if(h<arr[i])
        {
            // cap+=arr[i]-h;
            continue;
        }
        else
        {
            cap+=h-arr[i];
        }
    }
    return cap;
}
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }`````````````````
    int left=0,right=10e10+5;
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(tank(arr,mid)<=x)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    cout<<((tank(arr,right)<=x)?right-1:left-1)<<"\n";
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