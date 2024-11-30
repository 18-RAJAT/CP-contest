#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    for(int i=n-1;i>=0 && d>=1;--i)
    {
        if(s[i]=='@')
        {
            s[i]='.',d--;
        }
    }
    cout<<s<<endl;
}
signed main()
{
    sol();
    return 0;
}