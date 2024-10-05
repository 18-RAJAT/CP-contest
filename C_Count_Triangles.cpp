#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[10000005];
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;++i)
    {
        arr[b+i]++,arr[c+i+1]--;
    }
    int ans=0,count=0;
    for(int i=b;i<=b+c+2;++i)
    {
        count+=arr[i];
        ans+=count*(min(max(0LL,i-c),d-c+1));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}