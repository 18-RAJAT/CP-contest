#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<k;i++)
    {
        cin>>a[i];
    }
    int temp[k];
    map<int,int>mp;
    for(int i=0;i<k;i++)
    {
        cin>>temp[i];
        mp[a[i]]=temp[i];
    }
    for(int i=1;i<=n;i++)
    {
        int ans=INT_MAX;
        for(int j=0;j<k;j++)
        {
            //apply(distance=abs(x1-x2)+abs(y1-y2))
            if(a[j]<0)
            {
                continue;
            }
            int diff=abs(a[j]-i);//distance from the current air conditioner
            diff+=mp[a[j]];//time taken to reach the current air conditioner
            ans=min(ans,diff);//minimum time taken to reach the current air conditioner
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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