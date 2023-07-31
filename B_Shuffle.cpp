#include<bits/stdc++.h>
using namespace std;
void sol()
{
    long long n,x,m;
    cin>>n>>x>>m;
    long long mn(INT_MAX),mx=0;
    bool ok=false;
    for(long long i=0;i<m;++i)
    {
        long long l,r;
        cin>>l>>r;
        if(l<=x && r>=x && !ok)
        {
            ok=true;
            mn=l,mx=r;
        }
        else if(ok)
        {
            if(r>=mn && l<=mx)
            {
                mn=min<long long>(mn,l);
                mx=max<long long>(mx,r);
            }
        }
    }
    cout<<(ok?mx-mn+1:1)<<"\n";
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}