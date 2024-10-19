#include<bits/stdc++.h>
using namespace std;
#define int long long
int digit(char c){return (c-'A'+1);}
vector<int>numbers={0,1,10,100,1000,10000};
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>suffix(n+1);
    vector<int>a(n+1);
    vector<vector<int>>dp(n+1,vector<int>(6));
    for(int i=n-1;~i;--i)
    {
        a[i]=a[i+1]+(digit(s[i])<suffix[i+1]?-1:1)*numbers[digit(s[i])];
        suffix[i]=max<int>(digit(s[i]),suffix[i+1]);
        for(int j=0;j<6;++j)
        {
            dp[i][j]=dp[i+1][j]+(digit(s[i])>=j);
        }
    }
    vector<vector<int>>ndp(n+1,vector<int>(6,0));
    int ans=a[0];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=5;++j)
        {
            if(j<suffix[i+1] && dp[i+1][j+1]>=2)continue;
            auto& take=ndp[i+1][j],&not_take=ndp[i+1][j];
            if(digit(s[i])<j)
            {
                not_take=-numbers[digit(s[i])]+ndp[i][max<int>(digit(s[i]),j)];
            }
            else
            {
                take=numbers[digit(s[i])]+ndp[i][max<int>(digit(s[i]),j)];
            }
        }
        for(int j=1;j<=5;++j)
        {
            ans=max<int>(ans,ndp[i][max<int>(j,suffix[i+1])]+(j<suffix[i+1]?-1:1)*numbers[j]+a[i+1]);
        }
    }
    cout<<ans<<endl;
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