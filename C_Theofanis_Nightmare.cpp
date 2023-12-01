#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i]*(i+1);
    }
    int last=a[n-1];
    sum=a[n-1];
    vector<int>ans;
    for(int i=n-2;i>=0;--i)
    {
        int res=sum-last;
        if((res+a[i]+last)<=(2*sum+a[i]))
        {
            sum+=a[i];
            ans.emplace_back(last);
            last=a[i];
        }
        else
        {
            sum+=a[i];
            last+=a[i];
        }
    }
    ans.emplace_back(last);
    // sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    sum=0;
    int sza=ans.size();
    for(int i=0;i<sza;++i)
    {
        sum+=ans[i]*(i+1);
    }
    cout<<sum<<endl;
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