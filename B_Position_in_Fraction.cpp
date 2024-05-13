#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=505;++i)
    {
        a*=10;
        if(a/b==c)
        {
            cout<<i<<endl;
            return;
        }
        a%=b;
    }
    cout<<-1<<endl;
}
signed main()
{
    sol();
    return 0;
}