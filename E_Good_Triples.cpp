#include<bits/stdc++.h>
using namespace std;
#define int long long
int dig_sum[10];
void good()
{
    for(int i=0;i<10;++i)
    {
        dig_sum[i]=(i+1)*(i+2)/2;
    }
}
void sol()
{
    int n;
    cin>>n;
    int ans=1;
    while(n>=1)
    {
        ans*=dig_sum[n%10];
        n/=10;
    }
    cout<<ans<<endl;
}
signed main()
{
    int t;
    cin>>t;
    good();//precompute the sum of digits from 1 to i
    while(t--)
    {
        sol();
    }
    return 0;
}