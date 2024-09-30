#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int b,c,d;
    cin>>b>>c>>d;
    int Mask=0,Bit=0;
    for(int i=0;i<62;++i)
    {
        int x=(b>>i&1),y=(c>>i&1);
        if(x && !y)Mask^=1LL<<i;
    }
    if((d|Mask)!=d)
    {
        cout<<-1<<endl;
        return;
    }
    Mask=d^Mask;
    for(int i=0;i<62;++i)
    {
        if((Mask>>i)&1)
        {
            int x=(b>>i&1),y=(c>>i&1);
            if(!x &&!y)Bit+=1LL<<i;
        }
        else
        {
            int x=(b>>i)&1,y=(c>>i)&1;
            if(x && y)Bit+=1LL<<i;
        }
    }
    cout<<((((Bit|b)-(Bit&c))!=d)?-1:Bit)<<endl;
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