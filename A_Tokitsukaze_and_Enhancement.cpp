#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;
    cin>>x;
    auto check=[&](int val)->int
    {
        if(val%4==1)
        {
            return 'A';
        }
        else if(val%4==3)
        {
            return 'B';
        }
        else if(val%4==2)
        {
            return 'C';
        }
        else
        {
            return 'D';
        }
    };
    char ch='E';
    int ans=0;
    for(int i=0;i<3;++i)
    {
        if(check(x+i)<ch)
        {
            ch=check(x+i);
            ans=i;
        }
    }
    cout<<ans<<" "<<ch<<"\n";
}
signed main()
{
    sol();
    return 0;
}