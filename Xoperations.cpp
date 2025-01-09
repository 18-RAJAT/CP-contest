#include<bits/stdc++.h>
using namespace std;
#define int long long
int Pow(int x)
{
    return x!=0&&(x&(x-1))==0;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=n;
    for(int i=0;i<n-1;++i)
    {
        if(a[i]==a[i+1] || Pow(a[i]^a[i+1]))++ans;
    }
    int p=0;
    while(p<n)
    {
        int m=1;
        while(p+m<n && a[p+m]==a[p])m++;
        if(m>=3)ans+=((m-1)*(m-2))/2;
        p+=m;
    }
    cout<<ans<<endl;
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