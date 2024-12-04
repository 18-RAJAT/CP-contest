#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<tuple<int,int,int>>tp(n);
    for(int i=0;i<n;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tp[i]=make_tuple(a,b,c);
    }
    bool ok=true;
    if(n>0)
    {
        tuple<int,int,int>first=tp[0];
        for(int i=1;i<n;++i)
        {
            if(tp[i]!=first)
            {
                ok=false;
                break;
            }
        }
    }
    int t;
    cout<<(ok?t=n+2:t=n+3);
}
signed main()
{
    sol();
    return 0;
}