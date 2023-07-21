#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int a,b,c;cin>>a>>b>>c;
        int v=((a+b+c-min({a,b,c})));
        cout<<(v>9?"YES\n":"NO\n");
    }
}