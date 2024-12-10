#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int m,s;
    cin>>m>>s;
    if(s<1 && m>1 || m*9<s)
    {
        cout<<"-1 -1";
        return;
    }
    int mx=s;
    for(int i=m-1;~i;--i)
    {
        int M=max<int>(0,mx-9*i);
        if(M==0 && i==m-1 && mx)M=1;
        cout<<M;
        mx-=M;
    }
    cout<<" ";
    int mn=s;
    for(int i=m-1;~i;--i)
    {
        int M=min<int>(9,mn);
        cout<<M;
        mn-=M;
    }
}
signed main()
{
    sol();
    return 0;
}