#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a(200005);
int func()
{
    a[0]=1LL;
    for(int i=1;i<200005;++i)
    {
        a[i]=a[i-1]<<1;
        a[i]%=1000000007;
    }
}
signed main()
{
    func();
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int count=0;
        for(int i=0;i<m;++i)
        {
            int x,y,z;
            cin>>x>>y>>z;
            count|=z;
        }
        cout<<a[n-1]*count%1000000007<<endl;
    }
    return 0;
}