#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    // reverse(ans.begin(),ans.end());

    int right=n-1,left=n;
    left-=k,left--;

    int positions=0;
    while(k>=1)
    {
        if(ans[left]==ans[right])
        {
            positions++;
            ans[left]=0,ans[right]=0;
            left--,right--;
        }
        else
        {
            ans[left]=0,ans[right]=0;
            left--,right--;
        }
        k--;
    }
    for(auto& it:ans)
    {
        positions+=it;
    }
    cout<<positions<<endl;
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