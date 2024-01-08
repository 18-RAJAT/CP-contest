#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    int count[n+1];
    for(int i=1;i<=n;++i)
    {
        count[i]=(count[i-1])+(s[i-1]=='+'?true:false);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int plus=count[j]-count[i-1];
            int minus=j-i-plus;
            if((1+minus-plus)%3==0 && plus<=1+minus)
            {
                ans++;
            }
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