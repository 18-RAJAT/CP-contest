#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;++i)cin>>a[i],sum+=a[i];
    int x=sum/n,k=sum-n*x;
    if(k==0)
    {
        int ok=1;
        for(int i=0;i<n;++i)
        {
            if(a[i]!=x)
            {
                ok=0;
                break;
            }
        }
        cout<<(ok?"0":"-1")<<endl;
    }
    else cout<<k<<endl;
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