#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int ans=1e18;
    for(int i=0;i<=2e5;++i)
    {
        vector<int> check;
        for(int j=0;j<n;++j)
        {
            int moves=0;
            int temp=a[j];
            while(i<temp)
            {
                temp/=2;
                moves++;
            }
            if(i==temp)
            {
                check.push_back(moves);
            }
        }
        if(check.size()<k)
        {
            continue;
        }
        sort(check.begin(),check.end());
        int res=0;
        for(int j=0;j<k;++j)
        {
            res+=check[j];
        }
        ans=min(ans,res);
        check.clear();
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}