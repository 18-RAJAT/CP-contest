#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
void sol()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]>-1)
        {
            sum+=a[i];
        }
    }
    if(n<2)
    {
        cout<<sum<<endl;
    }
    else
    {
        if(a[1]<0 && a[2]>0)
        {
            int ert=sum-abs(a[1]);
            int calc=sum-abs(a[2]);
            sum=max(calc,ert);
        }
        cout<<sum<<endl;
    }
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