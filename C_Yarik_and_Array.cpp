#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0,res=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sum=a[0],res=a[0];
    for(int i=1;i<n;++i)
    {
        if((a[i]&1)==(a[i-1]&1) || sum<1)
        {
            sum=0;
        }
        sum+=a[i];
        res=max<int>(res,sum);
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