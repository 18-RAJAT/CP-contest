#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int one,two,three,four;
    cin>>one>>two>>three>>four;
    int ans=four/2;
    cout<<ans+one/2+two/2+three/2+(one%2 && two%2 && three%2?1:0)<<endl;
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