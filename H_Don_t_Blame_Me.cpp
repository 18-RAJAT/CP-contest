#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<map<int,int>>dp;
int transitions(int index,int n,vector<int>&v,int cur_and,int k)
{
    if(index==n)
    {
        bitset<32>b(cur_and);//converts cur_and to binary
        return b.count()==k;//returns the number of set bits in cur_and
    }
    int &res=dp[index][cur_and];
    // if(~res)
    // {
    //     return res;
    // }
    int res1=transitions(index+1,n,v,cur_and&v[index],k);//take the current element
    int res2=transitions(index+1,n,v,cur_and,k);//don't take the current element
    return res=res1+res2%1000000007;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    dp.clear();
    dp.resize(n);
    vector<int>v(n);
    for(auto &val:v)
    {
        cin>>val;
    }
    cout<<transitions(0,n,v,INT_MAX,k)%1000000007<<endl;
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