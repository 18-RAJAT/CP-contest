#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int temp=1;
    while(true)
    {
        int bit_and=(n&1);
        int current=n/2+bit_and;
        if(k<=current)
        {
            cout<<temp*(2*k-1)<<endl;
            break;
        }
        else
        {
            k-=current,temp<<=1,n>>=1;
        }
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