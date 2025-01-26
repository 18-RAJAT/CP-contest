#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int z=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='1')z++;
    }
    cout<<z<<endl;
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