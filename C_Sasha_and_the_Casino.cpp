#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k,x,a;
    cin>>k>>x>>a;
    int count=0;
    int ans=1;
    x++;
    while(x--)
    {
        ans+=count/(k-1)/2;
        ans=count/(k-1)+1;
        count+=ans;
        if(a<count)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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