#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& i:a)cin>>i;
    int ok=1;
    if(n>2)ok=0;
    else
    {
        ok=(abs(a[0]-a[1])==1)?0:1;
    }
    cout<<(ok?"YES":"NO")<<endl;
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