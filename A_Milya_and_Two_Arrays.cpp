#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    unordered_set<int>s1,s2;
    for(auto& it:a)s1.insert(it);
    for(auto& it:b)s2.insert(it);
    int x=s1.size(),y=s2.size(),ok=0;
    if(y>=3)ok=1;
    else if(y==1 && x>=3)ok=1;
    else if(y==2 && x>=2)ok=1;
    cout<<(ok?"YES":"NO")<<endl;
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