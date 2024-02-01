#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int d;
    cin>>d;
    int check=d*d-4*d;
    (check<0)?cout<<"N"<<endl:cout<<"Y "<<fixed<<setprecision(10)<<(d+sqrt(check))/2<<" "<<(d-sqrt(check))/2<<endl;
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