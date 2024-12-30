#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int cnt=0;
    while(a.size()>=2)
    {
        sort(a.begin(),a.end());
        vector<int>v;
        for(int i=0;i+1<a.size();++i)
        {
            if(a[i]!=a[i+1])v.push_back(a[i+1]-a[i]);
            else cnt++;
        }
        if(cnt)v.push_back(0),cnt--;
        a=move(v);
    }
    cout<<a[0]<<endl;
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