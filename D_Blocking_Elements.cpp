#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>temp=a;
    for(int i=1;i<n;++i)
    {
        temp[i]+=temp[i-1];
    }
    int sum=0;
    for(int i=0;i<n;++i)sum+=a[i];
    multiset<int>ms;
    int l=0,r=sum,ans=r;
    while(l<r)
    {
        int last=n-1;
        int mid=(l+r)/2;
        vector<int>dp(n+1,0);
        ms.clear();
        for(int i=n-1;i>=0;--i)
        {
            ms.insert(dp[i+1]+a[i]);
            int check=i?temp[i-1]:0;
            if(temp[n-1]-check<=mid)continue;
            dp[i]=1e18;

            while(i<last && mid<temp[last-1]-check)
            {
            	multiset<int>::iterator it=ms.find(a[last]+dp[last+1]);
            	if(it!=ms.end())ms.erase(it);
            	last--;
            }
            dp[i]=(ms.empty())?1e18:*ms.begin();
        }
        if(dp[0]<=mid)ans=mid,r=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    assert(n>=0);
    assert(!a.empty());
    assert(accumulate(a.begin(),a.end(),0LL)>=0);
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