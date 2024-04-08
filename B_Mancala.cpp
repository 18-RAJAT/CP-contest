#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    array<int,14>a;
    for(int i=0;i<14;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<14;++i)
    {
        array<int,14>b=a;
        int x=a[i];
        b[i]=0;
        for(int j=0;j<14;++j)
        {
            b[j]+=x/14;
        }
        x%=14;
        for(int j=1;j<=x;++j)
        {
            b[(i+j)%14]++;
        }
        int sum=0;
        for(int j=0;j<14;++j)
        {
            ((~b[j])&1?sum+=b[j]:sum+=0);
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}