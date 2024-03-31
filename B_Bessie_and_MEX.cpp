#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0];
        a[i][1]=i;
    }
    vector<int>cnt(n);
    cnt[a[n-1][1]]=n-a[n-1][0];
    int chk=cnt[a[n-1][1]];
    for(int i=n-2;~i;--i)
    {
        cnt[a[i][1]]=chk-a[i][0];
        chk=min(chk,cnt[a[i][1]]);
    }
    for(int i=0;i<cnt.size();++i)
    {
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
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