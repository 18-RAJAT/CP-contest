#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0,ans=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='O')
        {
            cnt++;
            if(cnt>=k)ans++,cnt=0;
        }
        else cnt=0;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}