#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int front=(k+1)/2;
    int back=k-front;
    for(int i=0;i<n;++i)
    {
        (front>=a[i])?(front-=a[i],a[i]=0):(a[i]-=front,front=0);
    }
    for(int i=n-1;~i;--i)
    {
        (back>=a[i])?(back-=a[i],a[i]=0):(a[i]-=back,back=0);
    }
    int res=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=0)res++;
    }
    cout<<res<<endl;
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