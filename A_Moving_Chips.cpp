#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int start=0,end=0,ans=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            start=1,ans+=end,end=0;
        }
        else if(start==1 && x==0)
        {
            end++;
        }
    }
    cout<<ans<<endl;
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