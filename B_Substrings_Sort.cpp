#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    sort(s,s+n,[](string a,string b)->bool
    {
        return a.size()<b.size();
    });
    bool ok=false;
    for(int i=0;i<n-1;++i)
    {
        if(s[i+1].find(s[i])==string::npos)
        {
            ok=true;
            break;
        }
    }
    if(ok)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)
        {
            cout<<s[i]<<endl;
        }
    }
}
signed main()
{
    sol();
    return 0;
}