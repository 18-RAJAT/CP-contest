#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l=2,h=1000;
    while(l<h)
    {
        int mid=l+(h-l)/2;
        cout<<"? 1 "<<mid<<endl;
        int x;
        cin>>x;
        (x==mid)?l=mid+1:h=mid;
    }
    cout<<"! "<<l<<endl;
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