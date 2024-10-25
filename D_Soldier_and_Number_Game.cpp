#include<bits/stdc++.h>
using namespace std;
#define int long long
int GetMaxSteps(int n)
{
    int steps=0;
    for(int i=2;i*i<=n;++i)
    {
        while(n%i==0)
        {
            steps++,n/=i;
        }
    }
    if(n>=2)steps++;
    return steps;
}
void sol()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=b+1;i<=a;++i)
    {
        ans+=GetMaxSteps(i);
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