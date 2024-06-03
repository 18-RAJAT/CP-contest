#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;++i)
    {
        if(s[i]!='4' && s[i]!='7')
        {
            cout<<"NO";return;
        }
    }
    int ans=0,tmp=0;
    for(int i=0;i<n/2;++i)
    {
        ans+=s[i];
    }
    for(int i=n/2;i<n;++i)
    {
        tmp+=s[i];
    }
    cout<<((ans==tmp)?"YES":"NO");
}
signed main()
{
    sol();
    return 0;
}