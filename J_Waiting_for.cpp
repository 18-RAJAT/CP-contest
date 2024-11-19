#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        char ch;
        cin>>ch;
        if(ch=='P')
        {
            int x;
            cin>>x;
            ans+=x;
        }
        else if(ch=='B')
        {
            int x;
            cin>>x;
            cout<<(ans<x?"YES":"NO")<<endl;
            ans=(ans<=x)?0:ans-x;
        }
    }
}
signed main()
{
    sol();
    return 0;
}