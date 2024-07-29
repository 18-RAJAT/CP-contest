#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<=n/1234567;++i)
    {
        int tmp=n-1234567*i;
        for(int j=0;j<=tmp/123456;++j)
        {
            if((tmp-123456*j)%1234==0){cout<<"YES";return;}
        }
    }
    cout<<"NO";
}
signed main()
{
    sol();
    return 0;
}