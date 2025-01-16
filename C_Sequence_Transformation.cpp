#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int seq=1;
    while(n)
    {
        if(n==3)
        {
            cout<<seq<<" "<<seq<<" "<<seq*3;
            return;
        }
        for(int i=1;i<=n-(n/2);++i)cout<<seq<<" ";
        seq*=2,n/=2;
    }
}
signed main()
{
    sol();
    return 0;
}