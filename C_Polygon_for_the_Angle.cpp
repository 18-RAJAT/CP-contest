#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int ang;
    cin>>ang;
    int ans(-1);
    for(int i=3;i<=2000005;++i)
    {
        long double x=(long double)180*(i-2);
        for(int j=0;j<=i-3;++j)
        {
            if(x-(long double)j*180==(long double)ang*i)
            {
                ans=i;
                break;
            }
        }
        if(~ans)
        {
            break;
        }
    }
    cout<<ans<<endl;
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