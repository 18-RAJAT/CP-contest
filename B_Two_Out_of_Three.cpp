#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
int b[105];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<105;++i)
    {
        b[i]=0;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    int cnt=0;
    int dp[2];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<105;++i)
    {
        if(b[i]>1 && cnt<=1)
        {
            dp[cnt]=i;
            cnt++;
        }
    }
    if(cnt!=2)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]==dp[0])
        {
            cout<<2;
            // cout<<i<<" ";
            dp[0]=-1;///set
            // break;
        }
        else if(a[i]==dp[1])
        {
            cout<<3;
            // cout<<i<<" ";
            dp[1]=-1;///set
            // break;
        }
        else
        {
            cout<<1;
            // cout<<i<<" ";
        }
        cout<<" ";
    }
    cout<<endl;
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