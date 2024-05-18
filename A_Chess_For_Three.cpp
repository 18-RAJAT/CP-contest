#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(((a+b+c)%2==1))
    {
       cout<<-1<<endl;
    }
    else
    {
       int res=min(a+b,(a+b+c)/2);
       cout<<res<<endl;
    }
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