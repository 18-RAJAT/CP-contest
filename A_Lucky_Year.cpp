#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n<10)
    {
        cout<<1<<endl;
        return;
    }
    int m=n,k=1,x;
    for(int i=0;m>0;++i)
    {
        x=m%10,k*=10,m/=10;
    }
    k/=10;
    cout<<((x+1)*k)-n;
}
signed main()
{
    sol();
    return 0;
}