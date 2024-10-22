#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,arr[500005];
double p[500005],w[500005];
vector<int>a[101];
void sol()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x==100)
        {
            sum+=y;
            continue;
        }
        p[i]=1.0*x/100.0,arr[i]=y;
        a[x].push_back(y);
    }
    w[0]=1;
    for(int i=1;i<=99;++i)
    {
        sort(a[i].begin(),a[i].end(),greater<int>());
        for(int j=0;j<a[i].size();++j)
        {
            double now=1.0*a[i][j]*i/(100-i);
            for(int k=now;~k;--k)
            {
                w[k+a[i][j]]=max(w[k+a[i][j]],w[k]*i/100.0);
            }
        }
    }
    double ans=0;
    for(int i=0;i<=100000;++i)ans=max(ans,w[i]*(i+sum));
    cout<<fixed<<setprecision(10)<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}