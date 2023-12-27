#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int maxi,mini;
    for(int i=0;i<n;++i)
    {
        if(i!=0 && i!=n-1)
        {
            maxi=max<int>(a[i]-a[0],a[n-1]-a[i]);
            mini=min<int>(a[i]-a[i-1],a[i+1]-a[i]);
        }
        else if(i==0)
        {
            maxi=a[n-1]-a[i];
            mini=a[i+1]-a[i];
        }
        else
        {
            maxi=a[i]-a[0];
            mini=a[i]-a[i-1];
        }
        cout<<mini<<" "<<maxi<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}