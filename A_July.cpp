#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    getline(cin,s);
    int st=s.find(' ');
    string num=s.substr(0,st);
    cout<<num;
}
signed main()
{
    sol();
    return 0;
}