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
    int ans=1,end=INT_MAX;
    for(int i=n-1;~i;--i)
    {
        if(a[i]<=end)
        {
            end=a[i];
            continue;
        }
        bool ok=1;
        int cur=a[i];
        while(cur)
        {
            ok&=(cur%10)<=end;
            end=cur%10;
            cur/=10;
        }
        ans&=ok;
    }
    cout<<((ans)?"YES":"NO")<<endl;
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