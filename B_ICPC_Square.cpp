#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int,int>memo;
int n,d,s,cnt=0;
int dfs(int x)
{
    if(memo.count(x))return memo[x];
    if(cnt++>1e6)return x;
    int ans=x,calc=min((d/x)+1,n/x);
    for(int i=calc;i>=2;--i)
    {
        int y=x*i;
        if(y>n)continue;
        if(y-x>d)continue;
        ans=max(ans,dfs(y));
    }
    memo[x]=ans;
    return ans;
}
void sol()
{
    cin>>n>>d>>s;
    cout<<dfs(s)<<endl;
}
signed main()
{
    sol();
    return 0;
}