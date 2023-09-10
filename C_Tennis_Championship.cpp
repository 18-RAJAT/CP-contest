#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a=0,b=1,c=1;
    int ans=0;
    while(c<=n)
    {
        c=a+b;
        int tmp=b;
        b=c;
        a=tmp;
        ans++;
    }
    cout<<ans-2;
}