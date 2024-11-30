#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(auto& p:arr)cin>>p;
    vector<double>p(n+1,0.0);
    p[0]=1.0;
    int maxi=0;
    for(int i=0;i<n;++i)
    {
        double prob=arr[i]/100.0;
        for(int i=maxi;~i;--i)
        {
            p[i+1]+=p[i]*prob;
            p[i]*=(1.0-prob);
        }
        maxi=min(maxi+1,n);
    }
    vector<double>e(x+1,0.0);
    e[x]=0.0;
    for(int k=x-1;k>=0;--k)
    {
        int current_s_max=min(n,x-1-k);
        double sum=0.0;
        for(int i=1;i<=current_s_max;++i)sum+=p[i]*e[k+i];
        double denominator=1.0-p[0];
        e[k]=(1.0+sum)/denominator;
    }
    cout<<fixed<<setprecision(10)<<e[0]<<"\n";
}
signed main()
{
    sol();
    return 0;
}