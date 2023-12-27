#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"FastestFinger"<<endl;
        return;
    }
    if(n&1 || n==2)
    {
        cout<<"Ashishgup"<<endl;
        return;
    }
    int ok=0;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i&1)
            {
                ok+=1;
            }
            int x=n/i;
            if(x&1)
            {
                ok+=1;
            }
        }
    }
    if((ok==0)?cout<<"FastestFinger"<<endl:(ok==1 && (n/2)%2)==1?cout<<"FastestFinger"<<endl:cout<<"Ashishgup"<<endl);
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