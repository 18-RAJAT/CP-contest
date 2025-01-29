#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string p[6]={"RGB","RBG","GRB","GBR","BRG","BGR"};
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=n;
    for(auto& it:p)
    {
        int c=0;
        for(int i=0;i<n;++i)if(s[i]!=it[i%3])c++;
        ans=min(ans,c);
        if(!ans)break;
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