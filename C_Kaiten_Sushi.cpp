#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;
    vector<int>arr(N+1,n+1),brr(N+1,n+1);
    for(int i=0;i<n;++i)
    {
        //[2,2e7]
        if(a[i]<=N)arr[a[i]]=min(arr[a[i]],i+1);
    }
    int tmp=n+1;
    for(int i=0;i<=N;++i)
    {
        //n[2,inf]
        if(i>=1 && arr[i]<=n)tmp=min(tmp,arr[i]);
        brr[i]=tmp;
    }
    for(int j=0;j<m;++j)
    {
        int x=b[j];
        if(x>N)x=N;
        if(x<0)x=0;
        if(brr[x]<=n)cout<<brr[x]<<endl;
        else cout<<"-1"<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}