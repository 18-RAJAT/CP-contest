#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int h,n;
    cin>>h>>n;
    vector<int>a(n),c(n);
    for(auto& it:a)cin>>it;
    for(auto& it:c)cin>>it;
    for(int i=0;i<n;++i)
    {
        h-=a[i];
    }
    if(h<1){cout<<1<<endl;return;}
    int left=0,right=1e12,ans=0;
    for(;left<=right;)
    {
        int check=0;
        int mid=left+(right-left)/2;
        for(int i=0;i<n;++i)
        {
            check+=(mid/c[i])*a[i];
            if(h<=check){break;}
        }
        (h-check<1)?ans=mid,right=mid-1:left=mid+1;
    }
    cout<<ans+1<<endl;
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