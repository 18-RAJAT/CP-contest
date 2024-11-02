
#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int m=2*n;
    int x=0,y=0;
    for(int i=0;i<m;++i)
    {
        int ai;
        cin>>ai;
        (ai==0)?x++:y++;
    }
    int ok=(x/2)+(y/2);
    cout<<n-ok<<" "<<min(x,y)<<endl;
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