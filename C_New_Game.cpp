#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
    }
    vector<pair<int,int>>game;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        game.push_back({it->first,it->second});
    }
    sort(game.begin(),game.end());
    int ans=0,l=0,r=0,sum=0,res=0;
    while(r<game.size())
    {
        if(ans<k)
        {
            if(l==r || game[r].first-game[r-1].first<=1)
            {
                sum+=game[r].second,ans++,res=max(res,sum),r++;
            }
            else
            {
                sum-=game[l].second,ans--,l++;
            }
        }
        else
        {
            sum-=game[l].second,ans--,l++;
        }
    }
    cout<<res<<endl;
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