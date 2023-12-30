#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    int ans=0,x,y;
    for(int i=1;i<61;++i)
    {
        x=(int)pow(2,i)-1;
        for(int j=0;j<i-1;++j)
        {
            y=(x-(int)pow(2,j));
            if(y>=a && y<=b)
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