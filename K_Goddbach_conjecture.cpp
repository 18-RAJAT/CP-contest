#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    const int N=10000000;
    vector<bool>P(N+1,true);
    P[0]=P[1]=false;
    for(int p=2;p*p<=N;++p)
    {
        if(P[p])
        {
            for(int i=p*p;i<=N;i+=p)
            {
                P[i]=false;
            }
        }
    }
    vector<int>G;
    G.reserve(500000);
    for(int x=9;x<=N && (int)G.size()<500000;x+=2)
    {
        if(!P[x] && P[x-2])
        {
            G.push_back(x);
        }
    }
    int C;
    cin>>C;
    while(C--)
    {
        int i;
        cin>>i;
        cout<<G[i-1]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}