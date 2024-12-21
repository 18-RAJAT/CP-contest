#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>b(n);
    for(int i=0;i<n;++i)cin>>b[i].first>>b[i].second;
    long double ans=-1e18;
    for(int j=0;j<n-1;++j)
    {
        int x1=b[j].first,h1=b[j].second,x2=b[j+1].first,h2=b[j+1].second;
        long double num=(long double)h1*x2-(long double)h2*x1;
        long double res=(long double)(x2-x1);
        long double c=num/res;
        ans=max(ans,c);
    }
    if(ans<0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<fixed<<setprecision(18)<<ans<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}