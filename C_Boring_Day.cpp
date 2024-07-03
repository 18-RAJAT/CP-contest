#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,r;
    cin>>n>>l>>r;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int sum=0,start=0,end=0,ans=0;
    for(;end<n;)
    {
        sum+=a[end];
        for(;r<sum;)
        {
            sum-=a[start++];
        }
        if(l<=sum && r>=sum)
        {
            ans++,start=end+1,sum=0;
        }
        end++;
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