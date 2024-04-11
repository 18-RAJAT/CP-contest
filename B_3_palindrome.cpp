#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    tuple<int,char>str[4];
    str[0]={97,'a'};
    str[1]={97,'a'};
    str[2]={98,'b'};
    str[3]={98,'b'};
    for(int i=0;i<n;++i)
    {
        cout<<(char)get<0>(str[i%4]);
    }
}
signed main()
{
    sol();
    return 0;
}