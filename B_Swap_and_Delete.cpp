#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int one=0,zero=0;
    for(int i=0;i<n;++i)
    {
        s[i]=='0'?zero++:one++;
    }
    int ans=n;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0' && one==0 || s[i]=='1' && zero==0)
        {
            break;
        }
        // swap<int>(one,zero);
        s[i]=='0'?one--:zero--;ans--;
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