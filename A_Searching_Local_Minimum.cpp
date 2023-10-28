#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N];
void ask(int query)
{
    cout<<"? "<<query<<endl;
    cin>>a[query];
}
int check(int mid)
{
    if(a[mid]==0)
    {
        ask(mid);
    }
    if(a[mid-1]==0)
    {
        ask(mid-1);
    }
    if(a[mid+1]==0)
    {
        ask(mid+1);
    }
    if(a[mid]<min(a[mid+1],a[mid-1]))
    {
        return 0;
    }
    if(a[mid]>a[mid-1])
    {
        return 1;
    }
    return 2;
}
signed main()
{
    int n;
    cin>>n;
    a[0]=a[n+1]=1e18;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int x=check(mid);
        if(x==0)
        {
            cout<<"! "<<mid<<endl;
            return 0;
        }
        else if(x==1)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return 0;
}