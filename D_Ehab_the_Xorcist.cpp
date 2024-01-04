#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int u,v;
    cin>>u>>v;
    if(v<u || (v-u)%2==1)
    {
        cout<<-1<<endl;
        return;
    }
    if(u==0 && v==0)
    {
        cout<<0<<endl;
        return;
    }
    if(u==v)
    {
        cout<<1<<endl;
        cout<<u;
        return;
    }
    int difference=abs<int>(v-u);
    int temp=difference/2;
    assert(temp>0 && temp<=v);
    if(u==((v-temp)^temp))
    {
        cout<<2<<endl;
        cout<<v-temp<<" "<<temp;
    }
    else
    {
        cout<<3<<endl;
        cout<<temp<<" "<<temp<<" "<<v-2*temp;
    }
}
signed main()
{
    sol();
    return 0;
}