#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,rb,cb,rd,cd;
    cin>>n>>m>>rb>>cb>>rd>>cd;
    int row=(rb<=rd)?(rd-rb):(n-rb+n-rd);
    int col=(cb<=cd)?(cd-cb):(m-cb+m-cd);
    cout<<min(row,col)<<"\n";
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