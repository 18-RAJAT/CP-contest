#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        bool sameCh=false;
        int left[n+1],right[n+1];
        int current=0;
        for(int i=0;i<n+1;++i)
        {
            left[i]=current;
            if(i<n && s[i]=='1')
            {
                current++;
            }
        }
        current=0;
        for(int i=n;i>=0;--i)
        {
            right[i]=current;
            if(i>0 && s[i-1]=='0')
            {
                current++;
            }
        }
        set<pair<int,int>>ans;
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=0;

        for(int i=1;i<n;++i)
        {
            dp[i]=dp[i-1];
            if(s[i-1]=='1' && s[i]=='0')
            {
                dp[i]++;
            }
        }
        for(int i=0;i<m;++i)
        {
            int l,r;
            cin>>l>>r;
            if(dp[r-1]-dp[l-1]==0)
            {
                sameCh=true;
                continue;
            }
            ans.insert({left[l-1],right[r]});
        }
        cout<<sameCh+ans.size()<<"\n";
    }
}