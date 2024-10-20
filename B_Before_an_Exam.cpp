#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int d,sum;
    cin>>d>>sum;
    vector<pair<int,int>>vp(d);
    vector<int>ans(d);
    for(int i=0;i<d;++i)
    {
        cin>>vp[i].first>>vp[i].second;
        ans[i]=vp[i].first;
        sum-=ans[i];
    }
    for(int i=0;i<d;++i)
    {
        while(ans[i]<vp[i].second && sum)
        {
            ans[i]++;
            sum--;
        }
    }
    cout<<(sum?"NO":"YES")<<endl;
    if(sum)return;
    for(int i=0;i<d;++i)cout<<ans[i]<<" ";
}
signed main()
{
    sol();
    return 0;
}