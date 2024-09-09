#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int k=1;
    do
    {
        if((n&1)==0)
        {
            n>>=1,k<<=1;
        }
        else break;
    }while(1);
    cout<<(n==1?-1:min(n,k<<1))<<endl;
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