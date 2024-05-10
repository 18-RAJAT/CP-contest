#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    function<void(string)> recur=[&](string s)->void
    {
        sort(s.begin(),s.end());
        if(s==string(n,s[0]))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
    };
    recur(s);
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