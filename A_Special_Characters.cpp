#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n/2;++i)
        {
            (i%2==0)?cout<<"AA":cout<<"BB";
        }
        cout<<endl;
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