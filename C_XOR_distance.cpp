#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,r;
    cin>>a>>b>>r;
    int ok=0,flag=0;
    int x=0;
    auto init=[&](int value,int op)->int
    {
        return((value>>op)&1);
    };
    for(int i=61;~i;--i)
    {
        auto left_shift=[&](int value,int op)->int
        {
            return(value<<op);
        };
        auto right_shift=[&](int value,int op)->int
        {
            return(value>>op);
        };
        if(ok)
        {
            if(init(a,i)!=init(b,i) && ((!flag && init(a,i)) || (flag && init(b,i))) && r>=(1LL<<i))
            {
                r-=(1LL<<i);
                // x|=(1LL<<i);
                x+=(1LL<<i);
            }
        }
        else if(init(a,i)!=init(b,i))
        {
            ok=1;
            // int temp=r;
            // (init(a,i))?temp-=(1LL<<i):temp+=(1LL<<i);
            // (temp>=0)?r=temp:ok=0;
            (init(a,i))?flag=0:flag=1;
        }
        // else
        // {
        //     if(init(a,i))
        //     {
        //         r+=(1LL<<i);
                // x|=(1LL<<i);
        //         x+=(1LL<<i);
        //     }
        // }
    }
    cout<<abs((a^x)-(b^x))<<endl;
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