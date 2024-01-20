#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r,a;
    cin>>l>>r>>a;
    int ans=0;
    if(l>r)
    {
        swap(l,r);
    }
    int Ambidexters=l+a;
    (Ambidexters<=r)?ans=2*Ambidexters:ans=2*r+2*((Ambidexters-r)/2);
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}