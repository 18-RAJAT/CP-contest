#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int frq[105];
int can(int days)
{
    int available=0;
    for(int i=0;i<105;++i)
    {
        int cur=frq[i];
        while(cur>=days)
        {
            cur-=days;
            available++;
        }
    }
    return available>=n?1:0;
}
int binarySearchOnAnswer(int l,int r)
{
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(can(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}

void sol()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        frq[x]++;
    }
    cout<<binarySearchOnAnswer(1,105)<<endl;
}

signed main()
{
    sol();
    return 0;
}