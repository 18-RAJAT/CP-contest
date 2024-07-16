#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    if(s.find('1')==string::npos)
    {
        cout<<"no";
        return;
    }
    s=s.substr(s.find('1'),s.size());
    if(count(s.begin(),s.end(),'0')<=5)cout<<"no";else cout<<"yes";
}
signed main()
{
    sol();
    return 0;
}