#include<bits/stdc++.h>
using namespace std;
#define int long long
int partition(vector<int>a,int k,int m)
{
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        if(a[i]<m)
        {
            k-=(m-a[i]),a[i]=m;
        }
        if(k<0)return 0;
    }
    int Cards=0,sum=0;
    for(int i=0;i<n;++i)
    {
        Cards=max(Cards,a[i]);
        sum+=a[i];
    }
    return (Cards*m-sum<=k);
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int Left=0,Right=1e8,ans=0;
    while(Left<=Right)
    {
        int mid=(Left+Right)>>1;
        (partition(a,k,mid))?Left=mid+1:Right=mid-1;
    }
    int sum=0,Cards=0;
    for(int i=0;i<n;++i)
    {
        Cards=max(Cards,a[i]);
        sum+=a[i];
    }
    for(int i=n-1;~i;--i)
    {
        int x=sum+k,y=i+1;
        if(sum-1<((x)/y)*y && Cards-1<((x)/y))
        {
            ans=i+1;
            break;
        }
    }
    int Optimal=min(n,ans);
    cout<<Optimal<<endl;
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
