#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>pr;
string s;
void sol()
{
    cin>>s;
    int count=0;
    for(int i=0;i<s.size();++i)
    {
        pr.push_back({-count,i});
        (s[i]=='(')?count++:count--;
    }
    sort(pr.rbegin(),pr.rend());
    for(auto& it:pr)cout<<s[it.second];
}
signed main()
{
    sol();
    return 0;
}