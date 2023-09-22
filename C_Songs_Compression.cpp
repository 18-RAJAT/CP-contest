#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int>&a,pair<int,int>&b)
{
    return a.first-a.second<b.first-b.second;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int valid=0;
    for(auto &val:b)
    {
        valid+=val;
    }
    if(valid>m)
    {
        cout<<-1<<endl;
    }
    else
    {
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            vp.emplace_back(a[i],b[i]);
        }
        sort(vp.begin(),vp.end(),cmp);
        int summation=0;
        for(auto &val:vp)
        {
            summation+=val.first;
        }
        int cnt=0;
        while(summation>m)
        {
            summation-=vp.back().first;
            summation+=vp.back().second;
            vp.pop_back();
            cnt++;
        }
        cout<<cnt<<endl;
    }
}
signed main()
{
    sol();   
    return 0;
}