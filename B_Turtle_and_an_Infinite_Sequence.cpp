#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(int l,int r)
{
    int res=0;
    while(l!=r)
    {
        l>>=1,r>>=1,res=(res<<1)|1;
    }
    int x=(l<<__builtin_popcount(res));
    return x|res;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    if(!m)
    {
        cout<<n<<endl;
        return;
    }
    int maxi=max(n-m,0LL),p=(n+m);
    cout<<find(maxi,p)<<endl;
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