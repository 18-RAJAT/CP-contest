#include<bits/stdc++.h>
using namespace std;
#define int long long

bool recur(int n,vector<int>& a)
{
    vector<int>suf(n,0);
    suf[n-1]=a[n-1];
    for(int i=n-2;~i;--i)
    {
        suf[i]=min(a[i],suf[i+1]);
    }
    for(int i=0;i<n-1;++i)
    {
        if(a[i]-suf[i+1]>=2)return false;
    }
    return true;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    cout<<(recur(n,a)?"YES":"NO")<<endl;
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