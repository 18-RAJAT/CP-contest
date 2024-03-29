#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol()
{
    int n;
    cin>>n;
    auto print=[&](int n)
    {
        (n==1)?cout<<"##":cout<<"..";
    };
    for(int i=0;i<2*n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if((i/2+j)%2==0)
            {
                print(1);
            }
            else print(0);
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