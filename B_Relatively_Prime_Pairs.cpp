#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    cout<<"YES"<<endl;
    for(int i=l;i<=r;i+=2)
    {
        cout<<i<<" "<<i+1<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}