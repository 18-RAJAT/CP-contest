#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,n;
    cin>>x>>n;
    int ans,balanced=1;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            ans=x/i;
            if(n<=ans)
            {
                balanced=max<int>(balanced,i);
            }
            if(n<=i)
            {
                balanced=max<int>(balanced,ans);
            }
        }
    }
    cout<<balanced<<endl;
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