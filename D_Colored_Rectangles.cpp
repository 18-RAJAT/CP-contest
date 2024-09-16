#include<bits/stdc++.h>
using namespace std;
#define int int

int recur(int r,int g,int b,vector<int>& Red,vector<int>& Green,vector<int>& Blue,vector<vector<vector<int>>>& dp)
{
    int ans=0;
    if(r<0 || g<0 || b<0)return 0;
    int& ret=dp[r][g][b];

    if(~ret)return ret;
    if(r>=1 && g>=1 && g!=0)ans=max(ans,recur(r-1,g-1,b,Red,Green,Blue,dp)+Red[r-1]*Green[g-1]);
    if(r>=1 && b>=1 && b!=0)ans=max(ans,recur(r-1,g,b-1,Red,Green,Blue,dp)+Red[r-1]*Blue[b-1]);
    if(g>=1 && b>=1 && r!=0)ans=max(ans,recur(r,g-1,b-1,Red,Green,Blue,dp)+Green[g-1]*Blue[b-1]);
    return ret=ans;
}
void sol()
{
    int r,g,b;
    cin>>r>>g>>b;
    vector<int>Red(r),Green(g),Blue(b);
    vector<vector<vector<int>>>dp;
    dp.assign(r+1,vector<vector<int>>(g+1,vector<int>(b+1,-1)));
    for(int i=0;i<r;++i)cin>>Red[i];
    for(int i=0;i<g;++i)cin>>Green[i];
    for(int i=0;i<b;++i)cin>>Blue[i];

    sort(Red.begin(),Red.end(),greater<int>());
    sort(Green.begin(),Green.end(),greater<int>());
    sort(Blue.begin(),Blue.end(),greater<int>());
    
    cout<<recur(r,g,b,Red,Green,Blue,dp);
}

signed main()
{
    sol();
    return 0;
}