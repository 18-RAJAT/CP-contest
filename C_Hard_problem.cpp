#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int r1=min(m,a),r2=min(m,b);
    int x=m-r1,y=m-r2;
    cout<<r1+r2+min(c,x+y)<<endl;
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