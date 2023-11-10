#include<bits/stdc++.h>
using namespace std;
#define int long long
int fx(int n,int k,int x)
{
    return (x%k)*((n-x)%k);
}
void sol()
{
    int n,k;
    cin>>n>>k;
    if(n<k)
    {
        cout<<n/2<<endl;
    }
    else
    {
        int a=n%k;
        int b=k+a;
        if(fx(n,k,a/2)<fx(n,k,b/2))
        {
            a=b;
        }
        cout<<a/2<<endl;
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