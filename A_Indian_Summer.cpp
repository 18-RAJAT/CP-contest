#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
	vector<pair<string,string>>vp(n);
    for(auto& it:vp)cin>>it.first>>it.second;
	set<pair<string,string>>s(vp.begin(),vp.end());
	cout<<s.size();
}
signed main()
{
    sol();
    return 0;
}