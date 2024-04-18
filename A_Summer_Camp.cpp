#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a;
    cin>>a;
    string pal;
    for(int i=0;i<1000;++i)
    {
        pal+=to_string(i);
    }
    cout<<pal[a];
}
signed main()
{
    sol();
    return 0;
}