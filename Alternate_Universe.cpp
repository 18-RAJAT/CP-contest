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
    int r=0;
    for(int i=n-1;~i;--i)
    {
        int op1=max<int>(r+1,a[i]+1);
        int op2=max<int>(r+1-b[i],0);
        r=(op2<=a[i])?min(op1,op2):op1;
    }
    cout<<r<<endl;
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