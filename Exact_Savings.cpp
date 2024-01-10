#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,z;
    cin>>n>>x>>z;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int sum=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        ans++;
        if(sum>=z)
        {
            break;
        }
    }
    if(n>1 && z%n==0)
    {
        cout<<n<<endl;
        return;
    }
    if(sum<z && ans==n)
    {
        cout<<-1<<endl; 
    }
    else
    {
        cout<<ans<<endl;
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