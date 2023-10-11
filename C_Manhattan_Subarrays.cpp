#include<bits/stdc++.h>
using namespace std;
#define int long long
int can(pair<int,int>p1,pair<int,int>p2)
{
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}
bool distEle(vector<pair<int,int>>arr)
{
    int n=arr.size();
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                int a=can(arr[i],arr[k]);
                int b=can(arr[i],arr[j]);
                int c=can(arr[j],arr[k]);
                if(a+b==c || b+c==a || a+c==b || a==0 || b==0 || c==0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>pr;
    for(int i=0;i<n;++i)
    {
        int v;
        cin>>v;
        pr.push_back(make_pair(v,i+1));
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int res=i+10;
        vector<pair<int,int>>arr;
        int mini=min(n,res);
        for(int j=i;j<mini;++j)
        {
            arr.push_back(pr[j]);
            ans+=distEle(arr);
        }
    }
    cout<<ans<<"\n";
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