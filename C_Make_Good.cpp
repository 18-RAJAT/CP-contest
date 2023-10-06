#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int X=0,check=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        check+=x;
        X^=x;
    }
    if(check==2*X)
    {
        cout<<0<<endl<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<X<<" "<<check+X<<endl;
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