#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k;
    cin>>k;
    if(k==0)
    {
        cout<<1<<" "<<1<<endl;
        cout<<"300000";
        return;
    }
    cout<<2<<" "<<3<<endl;
    cout<<131072+k<<" "<<131072<<" "<<0<<endl;
    cout<<k<<" "<<131072+k<<" "<<k<<endl;
}
signed main()
{
    sol();
    return 0;
}