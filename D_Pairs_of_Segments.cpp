#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n),merge;
    for(auto& it:a)cin>>it[0]>>it[1];
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i][0]<=a[j][1] && a[j][0]<=a[i][1])
            {
                merge.push_back({min(a[i][0],a[j][0]),max(a[i][1],a[j][1])});
            }
        }
    }
    sort(merge.begin(),merge.end(),[&](array<int,2>& a,array<int,2>& b){return a[1]<b[1];});
    int ans=-1,count=0;
    for(auto& it:merge)
    {
        if(ans<it[0])ans=it[1],count++;
    }
    cout<<n-(2*count)<<endl;
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