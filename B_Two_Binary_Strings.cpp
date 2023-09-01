#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b;
    cin>>a>>b;
    int n=a.size();
    bool ok=false;
    for(int i=1;i<n;++i)
    {
        if(a[i]==b[i] && a[i-1]==b[i-1] && a[i]=='1' && a[i-1]=='0' && b[i-1]=='0' && b[i]=='1')
        {
            cout<<"YES\n";  
            return;
        }
    }
    cout<<"NO\n";
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