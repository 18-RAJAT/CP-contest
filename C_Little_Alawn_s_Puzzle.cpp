#include<bits/stdc++.h>
using namespace std;

void sol()
{
    function<int(int,int)>binPow=[&](int a,int b)->int
    {
        int res = 1;
        while(b > 0)
        {
            if(b & 1) res = res*a%1000000007;
            a=a*a%1000000007;
            b>>=1;
        }
        return res;
    };
    int n;
    cin>>n;
    vector<int>puzzle(n),ans(n);
    
    for(auto&x:puzzle)cin>>x;
    for(auto&x:ans)cin>>x;

    int increaseCount=0;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp[make_pair(ans[i],puzzle[i])])
        {
            increaseCount++;
        }
        mp[make_pair(puzzle[i],ans[i])]=true;
    }
    int twoLines=2*increaseCount;
    if(twoLines!=n)
    {
        increaseCount++;
    }
    int findingAll=binPow(2,increaseCount);
    cout<<findingAll%1000000007<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}