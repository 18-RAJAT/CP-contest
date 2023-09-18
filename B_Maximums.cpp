#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,x,y,tmp=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        y=x+tmp;
        cout<<y<<" ";
        tmp=max(tmp,y);
    }
}