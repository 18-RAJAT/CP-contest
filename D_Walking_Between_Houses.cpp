#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,s;
    cin>>n>>k>>s;
    int pos=1,mn=0,mx=0;
    mn=k,mx=(n-1)*k;
    if(s<mn || s>mx)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=k-1;i>=0;--i)
    {
        int leave=i;
        int reach=min(n-1,s-leave);
        s-=reach;
        if(pos+reach<=n)
        {
            pos+=reach;
            cout<<pos<<" ";
        }
        else
        {
            pos-=reach;
            cout<<pos<<" ";
        }
    }
}
signed main()
{
    sol();
    return 0;
}