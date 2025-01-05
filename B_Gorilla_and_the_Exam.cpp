#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int>Fz;
    if(n>=1)
    {
        int ct=1;
        for(int i=1;i<n;++i)
        {
            if(a[i]==a[i-1])ct++;
            else
            {
                Fz.push_back(ct);
                ct=1;
            }
        }
        Fz.push_back(ct);
    }
    int tot=Fz.size(),sum=0,m=0;
    sort(Fz.begin(),Fz.end());
    for(auto& it:Fz)
    {
        if(sum+it<=k)sum+=it,m++;
        else break;
    }
    int ans=tot-m;
    if(ans<=0 && n>=1)ans=1;
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