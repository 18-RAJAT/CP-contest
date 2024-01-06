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
    for(int i=0;i<n;++i)
    {
        (s[i]=='+')?ans++:ans--;
    }
    cout<<abs<int>(ans)<<endl;
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