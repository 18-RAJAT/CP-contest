#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sol()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(n*m);
    ll tot=n*m;

    for(ll i=0;i<tot;++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll mn1=arr[0];
    ll mn2=arr[1];

    ll mx1=arr[tot-1];
    ll mx2=arr[tot-2];

    if(n<m)
    {
        swap(n,m);
    }
    ll ans1=abs(mx1-mn1)*(n-1)*(m)+abs(mx1-mn2)*(m-1);//(//n-2)*(m);

    ll ans2=abs(mx1-mn1)*(n-1)*(m)+abs(mx2-mn1)*(m-1);//(//m-2)*(n);

    cout<<max(ans1,ans2)<<"\n";
}
int main()
{
    int testCases;  
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}