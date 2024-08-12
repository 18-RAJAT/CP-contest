#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto& it:a)cin>>it;
    for(auto& it:b)cin>>it;
    if(a==b || equal(a.begin(),a.end(),b.rbegin()))cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
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