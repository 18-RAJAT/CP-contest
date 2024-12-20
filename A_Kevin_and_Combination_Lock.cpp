#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;
    cin>>x;
    int cnt=0,tmp=x;
    while(x>=1)
    {
        if(x%10==3)cnt++;
        x/=10;
    }
    int rem=tmp-(cnt/2)*33;
    cout<<((rem<0 || ((rem<33 && cnt>=2) || (rem>=33 && rem%33==0)))?"YES":"NO")<<endl;
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