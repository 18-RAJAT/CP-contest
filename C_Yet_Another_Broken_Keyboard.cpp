#include<bits/stdc++.h>
using namespace std;

class sol
{
    private:
    int n,k;
    vector<bool>works;
    string s;
    vector<int>dp;

    public:
    sol(int N,int K,string S):n(N),k(K),s(S)
    {
        works.resize(26,false);
        dp.resize(n+1,0);

        for(int i=0;i<k;++i)
        {
            char ch;
            cin>>ch;

            works[ch-'a']=true;
        }
    }
    long long cntSubString()
    {
        for(int i=1;i<=n;++i)
        {
            //base chk
            if(works[s[i-1]-'a'])//if it is true then it is a valid substring
            {
                //pruning directly if works[s[i-1]-'a']==true
                dp[i]=1+dp[i-1];
            }
            //end condition for dp[i] then dp[i-1]?
            // cout<<dp[i]<<" ";
        }
        return accumulate(dp.begin(),dp.end(),0ll);
        // return dp[n];
    }
    ~sol()
    {
        works.clear();
        dp.clear();
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    sol obj(n,k,s);
    cout<<obj.cntSubString()<<"\n";
    return 0;
}