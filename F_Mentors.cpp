#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[200005];
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    vector<int>v;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        int left=0,right=n-1;
        int curr=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(a[i]>v[mid])
            {
                curr=mid+1;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        ans[i]=curr;
    }
    for(int i=0;i<k;++i)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(a[x]>a[y])
        {
            ans[x]--;
        }
        else if(a[x]<a[y])
        {
            ans[y]--;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
}
signed main()
{
    sol();
    return 0;
}