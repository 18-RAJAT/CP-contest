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
    multiset<int>s,ms;
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        s.insert(b[i]);
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[i])ms.insert(b[i]);
    }
    int m;
    cin>>m;
    int ok=0;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        if(ms.count(x))
        {
            ms.erase(ms.find(x));
            if(i==m-1)ok=1;
        }
        else if(s.count(x))
        {
            if(i==m-1)ok=1;
        }
    }
    cout<<((ms.size()==0 && ok)?"YES":"NO")<<endl;
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