#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    vector<pair<int,double>>probability;//probability of sorting the prefix
    for(int i=0;i<m;i++)
    {
        int r;
        double p;
        cin>>r>>p;
        r--;
        probability.push_back({r,p});
    }
    double ans=1;
    for(int i=0;i<n;i++)
    {
        int j=i;
        double p=1;
        while(j<n && a[j]==j)
        {
            j++;
        }
        for(auto&it:probability)
        {
            if(it.first<j)
            {
                p*=(1-it.second);
            }
        }
        ans*=(1-p);
    }
    // int prob=round((1-ans)*1000000);//rounding off the answer
    // cout<<prob<<endl;
    cout<<fixed<<setprecision(6)<<1-ans<<endl;
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