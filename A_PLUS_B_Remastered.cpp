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
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    vector<int>c(n);
    for(int i=0;i<n;++i)
    {
        c[i]=a[i]+b[i];
    }
    bool flag=true;
    for(int i=0;i<n-1;++i)
    {
        if(c[i]!=c[i+1])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        for(auto& i:a)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto& i:b)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
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