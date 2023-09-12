#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
    	cin>>v[i].first;
    	v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<int>ans(n);
    int tmp=n;
    for(int i=0;i<n;i++)
    {
    	ans[v[i].second]=tmp--;
    }
    for(int i=0;i<n;i++)
    {
    	cout<<ans[i]<<" ";
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