#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    k--;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int x=k,y=-1;
    for(int i=k-1;i>=0;--i)
    {
        if(a[k]<a[i])
        {
            y=x,x=i;
        }
    }
    int res=INT_MIN;
    if(x<k)
    {
        if(x==0)
        {
            res=max(x-1,y-x-1);
        }
        else
        {
            res=max(x-1,y-x);
        }
    }
    else
    {
        for(int i=k+1;i<n;++i)
        {
            if(a[k]<a[i])
            {
                x=i;
                break;
            }
        }
        if(x==k)x=n;
        res=x-1;
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