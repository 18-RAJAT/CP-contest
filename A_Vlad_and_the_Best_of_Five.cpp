#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<5;++i)
    {
        (s[i]=='A')?a++:b++;
    }
    cout<<(a>b?"A":"B")<<endl;
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