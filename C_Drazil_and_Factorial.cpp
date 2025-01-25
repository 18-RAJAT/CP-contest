#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    array<string,10>ch={"","","2","3","223","5","53","7","7222","7332"};
    int n,a;
    cin>>n>>a;
    string s,st=to_string(a);
    for(auto& it:st)s+=ch[it-'0'];
    sort(s.begin(),s.end(),greater<char>());
    cout<<s;
}
signed main()
{
    sol();
    return 0;
}