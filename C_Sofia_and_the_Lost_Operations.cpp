#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    multiset<int>ms;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[i])ms.insert(b[i]);
    }
    int m;
    cin>>m;
    vector<int>check(m);
    int ok=0;
    for(int i=0;i<m;++i)
    {
        cin>>check[i];
        if(ms.count(check[i]))
        {
            ms.erase(ms.find(check[i]));
        }
    }
    for(int i=0;i<n;++i)
    {
        if(b[i]==check[m-1])ok=1;
    }
    if(!ms.empty())ok=0;
    cout<<((ok)?"YES":"NO")<<endl;
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