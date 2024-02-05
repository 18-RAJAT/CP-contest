#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vp(n);
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        vp[i].second=a[i];
    }
    for(int i=0;i<n;++i)
    {
        int count=0;
        while(a[i]%3==0)
        {
            a[i]/=3;
            count++;
        }
        vp[i].first=-count;//-count because we want to sort in descending order
    }
    sort(vp.begin(),vp.end());
    for(auto& [x,y]:vp)
    {
        cout<<y<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}