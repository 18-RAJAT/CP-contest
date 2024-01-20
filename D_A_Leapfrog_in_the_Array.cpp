#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        while(!(x&1))
        {
            x+=(n-x/2);
        }
        cout<<x/2+1<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}