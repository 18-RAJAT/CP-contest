#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y,k;
    cin>>x>>y>>k;
    int dx=(x+k-1)/k,dy=(y+k-1)/k;
    int xx=min(dx,dy),yy=max(dx,dy);
    int l1=yy-xx,l2=yy+xx;
    int jmp=l1+l2;
    if(dy<dx)jmp--;
    cout<<jmp<<endl;
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