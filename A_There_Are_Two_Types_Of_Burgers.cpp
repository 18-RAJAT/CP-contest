#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int b,p,f,h,c;
    cin>>b>>p>>f>>h>>c;
    int ans=0;
    for(int i=0;i<=100;++i)
    {
        for(int j=0;j<=100;++j)
        {
            int calc=(2*i+2*j);
            int x=b-calc;//remaining buns
            int y=p-i;//remaining patties
            int z=f-j;//remaining chicken
            if(x<0 || y<0 || z<0)
            {
                continue;
            }
            if(x>-1 && y>-1 && z>-1)
            {
                int profit=(i*h+j*c);
                // cout<<i<<" "<<j<<" "<<profit<<endl;
                ans=max(ans,profit);
            }
        }
    }
    cout<<ans<<endl;
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