#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>pref(n,0),suf(n,0);
    int ans=0,count=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='G')
        {
            pref[i]=(i>=1?pref[i-1]:0)+1,count++;
            ans=max(ans,pref[i]);
        }
        else pref[i]=0;
    }
    for(int i=n-1;~i;--i)
    {
        if(s[i]=='G') suf[i]=(i<n-1?suf[i+1]:0)+1;
        else suf[i]=0;
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='S')
        {
            int calc=(i>=1?pref[i-1]:0)+(i<n-1?suf[i+1]:0);
            ans=(abs(count-calc)>=1)?max(ans,calc+1):max(ans,calc);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}