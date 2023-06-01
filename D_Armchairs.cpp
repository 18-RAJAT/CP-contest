#include<bits/stdc++.h>
using namespace std;

int dp[50001];
int check[50001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>dp[i];
        check[i]=dp[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(dp[i])
        {
            int MN=1e9;
            int temp=0;
            for(int j=1;j<=n;++j)
            {
                if(not check[j])
                {
                    if(abs(i-j)<MN or dp[j])
                    {
                        MN=abs(i-j);
                        temp=j;
                    }
                }
            }
            check[temp]=1;
            ans+=MN;
        }
    }
    cout<<ans<<"\n";
}