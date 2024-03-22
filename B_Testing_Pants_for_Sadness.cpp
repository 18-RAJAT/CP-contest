#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        ans+=1+(i)*(x-1);
    }
    cout<<ans-1<<endl;
}
signed main()
{
    sol();
    return 0;
}