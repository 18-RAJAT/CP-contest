#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]*=(n-i);
    }
    int sum=0,ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        if(sum<=x)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    sol();
    return 0;
}