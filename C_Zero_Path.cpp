#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<bitset<1005>>previous(m+1),current(m+1);
    // previous[0][0]=1;
    current[1][0]=1;
    for(int i=1;i<=n;++i)
    {
        previous=current;
        // current.clear();
        current.assign(m+1,bitset<1005>());
        for(int j=1;j<=m;++j)
        {
            int path;
            cin>>path;
            path=max(path,0LL);
            // current[j]|=previous[j]<<path;//previous[j]<<path means previous[j] is shifted to the left by path bits
            current[j]=(current[j-1]|(current[j]))<<path;
        }
    }
    (n%2==m%2)?cout<<"NO"<<endl:cout<<(current[m][(n+m-1)/2])<<endl;
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