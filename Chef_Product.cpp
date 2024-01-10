#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
void sol()
{
    int n;
    cin>>n;
    auto Sqrt=[](int n)->int
    {
        int ans=sqrt(n);
        return ans;
    };
    if(n%2==0)
    {
        double chk=n;
        chk=chk/4;//for even n, n/4 is the answer
        int ans=sqrtl(chk);
        cout<<ans<<endl;
    }
    else
    {
        double chk=n+1;
        chk=sqrtl(chk);//for odd n, (n+1)/2 is the answer
        // ans=ans+1,ans/=2;
        chk=chk+1,chk=chk/2;
        int prod=chk;
        cout<<prod<<endl;
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