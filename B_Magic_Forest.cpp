#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            auto xor_check=[&](int x,int y)->int
            {
                return x^y;
            };
            if(xor_check(i,j)<=n && xor_check(i,j)>=j && i+j>xor_check(i,j))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}