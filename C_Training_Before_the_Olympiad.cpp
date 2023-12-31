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
    int sum=0,o=0,e=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        (a[i]%2)?o++:e++;
        if(i==0)
        {
            cout<<sum<<" ";
            continue;
        }
        int ans=sum-o/3;
        // cout<<"ans: "<<ans<<" ";
        if(o%3==1)
        {
            ans--;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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