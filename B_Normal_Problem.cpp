#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    for(char &c:s)
    {
        if(c=='p')c='q';
        else if(c=='q')c='p';
    }
    cout<<s<<endl;
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