#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,a,b;
    cin>>x>>a>>b;
    int time=a*60+b;
    function<bool(int)> check=[&](int x)->bool
    {
        int b=x%60;
        int a=x/60;
        if(b%10==7)
        {
            return true;
        }
        if(a%10==7)
        {
            return true;
        }
        if(b/10==7)
        {
            return true;
        }
        if(a/10==7)
        {
            return true;
        }
        return false;
    };
    for(int i=0;;++i)
    {
        if(check(time))
        {
            cout<<i<<endl;
            return;
        }
        time-=x;
        if(time<0)
        {
            time+=24*60;
        }
    }
    cout<<0<<endl;
}
signed main()
{
    sol();
    return 0;
}