#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NN=32000;

//RAJAT JOSHI TEMPLATE
vector<int>getPrimes(int x)
{
    vector<bool>isPrime(x+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=x;++i)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=x;j+=i)isPrime[j]=false;
        }
    }
    vector<int>Prime;
    for(int i=2;i<=x;++i)if(isPrime[i])Prime.push_back(i);
    return Prime;
}

map<int,int>getFactors(int num,const vector<int>& Prime)
{
    map<int,int>Facts;
    for(int i=0;i<Prime.size() && Prime[i]*Prime[i]<=num;++i)
    {
        while(num%Prime[i]==0)
        {
            ++Facts[Prime[i]];
            num/=Prime[i];
        }
    }
    if(num>1)++Facts[num];
    return Facts;
}

void sol()
{
    int a,b,n;
    cin>>a>>b>>n;
    vector<int>Prime=getPrimes(NN);
    vector<int>arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    map<int,int>Cnt;
    if(b>1)
    {
        map<int,int>B=getFactors(b,Prime);
        for(auto& it:B)Cnt[it.first]+=it.second;
    }
    for(int i=0;i<n;++i)
    {
        if(arr[i]>1)
        {
            map<int,int>A=getFactors(arr[i],Prime);
            for(auto& it:A)Cnt[it.first]+=it.second;
        }
    }
    if(a>1){
        map<int,int>Ft=getFactors(a,Prime);
        for(auto& it:Ft)
        {
            Cnt[it.first]-=it.second;
            if(Cnt[it.first]<0)
            {
                cout<<"-1";
                return;
            }
        }
    }
    vector<int>Fact;
    for(auto it:Cnt)
    {
        if(it.second<0)
        {
            cout<<"-1";
            return;
        }
        for(int i=0;i<it.second;++i)Fact.push_back(it.first);
    }
    int l=Fact.size();
    if(l>n)
    {
        cout<<"-1";
        return;
    }
    vector<vector<int>>adj(l);
    for(int i=0;i<l;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(arr[j]>=Fact[i])adj[i].push_back(j);
        }
    }
    vector<int>Tmp(n,-1);

    //RAJAT TEMPLATE
    auto dfs=[&](auto& dfs,int u,vector<bool>& vis)->bool
    {
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                if(Tmp[v]==-1 || dfs(dfs,Tmp[v],vis))
                {
                    Tmp[v]=u;
                    return true;
                }
            }
        }
        return false;
    };
    int matches=0;
    for(int i=0;i<l;++i)
    {
        vector<bool>vis(n,false);
        if(dfs(dfs,i,vis))++matches;
    }
    if(matches<l)
    {
        cout<<"-1";
        return;
    }
    vector<int>res(n,1);
    for(int i=0;i<n;++i)
    {
        if(~Tmp[i])res[i]=Fact[Tmp[i]];
    }
    for(int i=0;i<n;++i)cout<<res[i]<<" ";
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}