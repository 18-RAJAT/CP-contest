#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,r;cin>>a>>b>>c>>r;
        if(a>b)swap(a,b);
        int x=c-r,y=c+r;
        x=max<int>(x,a),y=min<int>(y,b);x=min<int>(x,b),y=max<int>(y,a);
        cout<<x-a+b-y<<"\n";
    }
}