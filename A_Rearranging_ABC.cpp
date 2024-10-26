#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    cout<<(s=="ABC"?"Yes":"No");
}
signed main()
{
    sol();
    return 0;
}