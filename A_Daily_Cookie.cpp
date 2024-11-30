#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    string s;
    cin>>n>>d>>s;
    int ok=count(s.begin(),s.end(),'@');
    cout<<n-(ok-d)<<endl;
}
signed main()
{
    sol();
    return 0;
}