#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    bool flag=false;
    int ans=0;
    int samePos=2;
    for(int i=1;i<=n;++i)
    {
        if(a[i-1]!=i)
        {
            if(!flag)
            {
                flag=true;
                ans++;
            }
        }
        else
        {
            flag=false;
        }
    }
    cout<<min(samePos,ans)<<"\n";
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