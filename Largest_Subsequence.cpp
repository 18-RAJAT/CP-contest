#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    // if(n==0)
    // {
    //     cout<<0<<endl;
    //     return;
    // }
    int ans=s[0],maxi=0;
    // for(int i=1;i<n;++i)
    // {
    //     ans+=s[i]!=s[i-1];
    // }
    // int cnt_a=0,cnt_b=0;
    for(int i=0;i<n;++i)
    {
        int first=s[i],last=s[n-1];
        (first==last)?maxi=max(maxi,n-i):maxi=max(maxi,i+1);
    }
    cout<<maxi<<endl;
    // for(int i=0;i<n;++i)
    // {
    //     if(s[i]=='a')++cnt_a;
    //     else ++cnt_b;
    // }
    // if(ans%2==0)cout<<n<<endl;
    // else
    // {
    //     (ans>=2)?cout<<n-1<<endl:cout<<max(cnt_a,cnt_b)<<endl;
    // }
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