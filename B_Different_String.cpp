#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    string t=s;
    sort(t.begin(),t.end());
    if(s==t)reverse(t.begin(),t.end());
    cout<<(((s==t)?"NO":"YES\n"+t))<<endl;
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