#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int ans=0;
    auto compute=[&](string& a,string& b,int n,int & ans)->void
    {
        for(int i=1;i+1<n;++i)
        {
            if(a[i-1]=='.' && a[i]=='.' && a[i+1]=='.' && b[i-1]=='x' && b[i]=='.' && b[i+1]=='x')ans++;
        }
    };
    for(int j=0;j<2;++j)
    {   compute(a,b,n,ans);
        swap(a,b);
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