#include <bits/stdc++.h>
using namespace std;
#define int long long
int count(int n,int x)
{
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n/i;++j)
        {
            int temp=(n-i*j)/(i+j);
            temp=min(temp,x-i-j);
            if(temp>=1)ans+=temp;
        }
    }
    return ans;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        cout<<count(n,x)<<endl;
    }
    return 0;
}
