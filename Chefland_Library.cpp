#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt=0;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>mp(100005,0),lt(100005,0),ans;
    cnt++;
    for(int i=1;i<=n;++i)
    {
        int d=a[i-1],p=i;
        if(lt[d]!=cnt)
        {
            lt[d]=cnt;
            mp[d]=p;
            ans.push_back(d);
        }
        else
        {
            if(p>mp[d])mp[d]=p;
        }
    }
    int sum=0;
    for(auto& it:ans)sum+=mp[it];
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