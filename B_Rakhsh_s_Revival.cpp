#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        int ans=0,cnt=0;
        for(int i=0;i<n;++i)
        {
            (s[i]=='0')?cnt++:cnt=0;
            if(cnt==m)
            {
                ans++,i+=k-1,cnt=0;
            }
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}