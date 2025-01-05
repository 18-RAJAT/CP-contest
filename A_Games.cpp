#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n],cnt=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(b[i]==a[j])cnt++;
        }
    }
    cout<<cnt;
}
signed main()
{
    sol();
    return 0;
}