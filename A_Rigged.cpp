#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    bool ok=1;
    int x1,x2;
    for(int i=0;i<n;++i)
    {
        if(i==0)
        {
            cin>>x1>>x2;
        }
        else
        {
            int y1,y2;
            cin>>y1>>y2;
            if(y1>=x1 && y2>=x2)
            {
                ok=0;
            }
        }
    }
    cout<<(ok==1?x1:-1)<<"\n";
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