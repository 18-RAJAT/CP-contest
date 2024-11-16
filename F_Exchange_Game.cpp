#include<bits/stdc++.h>
using namespace std;
#define int long long
int state3[10005];
void Init()
{
    state3[0]=1;
    for(int i=1;i<=10005;++i)state3[i]=state3[i-1]*3;
}
int state(const vector<int>& res,int k)
{
    int ans=0;
    for(int i=0;i<k;++i)ans+=res[i]*state3[i];
    return ans;
}
int k;
vector<char>dp;
vector<int>ndp;
bool Probability(int state,bool ok,const vector<vector<int>>& both)
{
    int turn=ok?0:1;
    int index=state*2+turn;
    // for(int i=0;i<dp.size();++i)
    // {
    //     if(dp[i]==-1)dp[i]=0;
    //     else if(dp[i]==0)return false;
    // }
    if(~dp[index])return dp[index];
    vector<int>res(k,0);
    int temp=state;
    for(int i=0;i<k;++i)
    {
        res[i]=temp%3,temp/=3;
    }
    int prob=ok?1:2;
    vector<int>b;
    for(int i=0;i<k;++i)
    {
        if(res[i]==prob)
        {
            b.push_back(i);
        }
    }
    if(b.empty())
    {
        dp[index]=0;
        return false;
    }
    for(auto& it:b)
    {
        vector<int>tp=res;
        tp[it]=0;
        int ert=0;
        for(int i=0;i<k;++i)ert+=tp[i]*state3[i];
        if(!Probability(ert,!ok,both))
        {
            dp[index]=1;
            return true;
        }
        // cout<<it<<endl;
        // for(int i=0;i<k;++i)cout<<tp[i]<<" ";
        // cout<<endl;
        for(auto& itr:both[it])
        {
            vector<int>tp1=tp;
            tp1[itr]=prob;
            int sum=0;
            for(int i=0;i<k;++i)sum+=tp1[i]*state3[i];
            if(!Probability(sum,!ok,both))
            {
                dp[index]=1;
                return true;
            }
        }
    }
    dp[index]=0;
    return false;
}
void sol()
{
    int N,M,L;
    cin>>N>>M>>L;
    k=N+M+L;
    ndp.resize(k);
    for(int i=0;i<k;++i)cin>>ndp[i];
    vector<vector<int>>both(k,vector<int>());
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            if(ndp[j]<ndp[i])both[i].push_back(j);
        }
    }
    // for(auto& it:both)
    // {
    //     for(auto& itr:it)cout<<itr<<" ";
    //     cout<<endl;
    // }
    vector<int>res(k,0);
    // dp[0]=1;
    for(int i=0;i<N;++i)res[i]=1;
    for(int i=N;i<N+M;++i)res[i]=2;
    // for(int i=N+M;i<k;++i)res[i]=3;
    dp.assign(2*state3[k],-1);
    // for(int i=0;i<dp.size();++i)
    // {
    //     if(dp[i]==-1)dp[i]=0;
    //     else if(dp[i]==0)dp[i]=0;
    //     if(i==10)
    //     {
    //         cout<<dp[i]<<endl;
    //     }
    //     for(int j=0;j<k;++j)
    //     {
    //         cout<<res[j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(Probability(state(res,k),true,both))cout<<"Takahashi";
    else cout<<"Aoki";
}
signed main()
{
    Init();
    sol();
}