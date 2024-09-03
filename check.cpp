#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[]={1,3,4,7,8,9};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    int sum=accumulate(a,a+n,0LL);
    int mini=INT_MAX,ans=0,k;
    for(int i=0;i<n;++i)
    {
        int temp=a[i];
        int calculate=(sum-ans-(n-i)*temp)+ans;
        if(calculate<mini)
        {
            mini=calculate,k=temp;
        }
        ans+=a[i];
    }
    cout<<"Min-operation:"<<mini<<" k:"<<k;
}
signed main()
{
    sol();
    return 0;
}