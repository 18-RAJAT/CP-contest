#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int tot=0,e=0,o=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        tot+=a[i];
        if((i+1)%2==0)e+=a[i];
        else o+=a[i];
    }
    if(tot%n!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    int ec=n/2,oc=n-ec;
    if(e*n==tot*ec && o*n==tot*oc)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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