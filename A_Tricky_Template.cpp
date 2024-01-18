#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int diff=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==c[i] || b[i]==c[i])
        {
            diff++;
        }
    }
    if(diff==n)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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