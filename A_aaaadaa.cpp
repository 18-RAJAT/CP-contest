#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    char c1,c2;
    string s;
    cin>>n>>c1>>c2>>s;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=c1)s[i]=c2;
    }
    cout<<s<<endl;
}
signed main()
{
    sol();
    return 0;
}