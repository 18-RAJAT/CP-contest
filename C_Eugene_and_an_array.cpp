#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    map<int,int>compute;
    compute[0]=1;
    int sum=0,add=1;
    for(int i=2;i<n+2;++i)
    {
        sum+=a[i-2];
        add=max<int>(add,compute[sum]+1);
        ans+=i-add;
        compute[sum]=i;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}