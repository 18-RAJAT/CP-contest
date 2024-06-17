#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    if((n&1)==0 && (m&1)==0)cout<<((k&1)==0?"YES\n":"NO\n");
    else
    {
        if(n&1)
        {
            int for_m=m/2;
            if((k<for_m)!=0){cout<<"NO\n";return;}
            k-=for_m;
            cout<<((k&1)==0?"YES\n":"NO\n");
        }
        else
        {
            int for_n=n/2;
            k=(n*m)/2-k;
            if((k<for_n)!=0){cout<<"NO\n";return;}
            k-=for_n;
            cout<<((k&1)==0?"YES\n":"NO\n");
        }
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