#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    //18=2*9,25=5*5,21=3*7
    //18=x,25=y,21=z
    int n;
    cin>>n;
    int x=n,y=n,z=n,ans=0;
    
    int cnt1=min(z/2,x);
    ans+=cnt1,z-=2*cnt1,x-=cnt1;
    
    int cnt2=min(z,x/2);
    ans+=cnt2,z-=cnt2,x-=2*cnt2;
    
    int cnt3=x/3;
    ans+=cnt3,x-=3*cnt3;

    int cnt4=y/2;
    ans+=cnt4,y-=2*cnt4;
    
    int cnt5=min(y,z);
    ans+=cnt5,y-=cnt5,z-=cnt5;
    
    int cnt6=min(y,x);
    ans+=cnt6,y-=cnt6,x-=cnt6;
    
    int cnt7=z/2;
    ans+=cnt7,z-=2*cnt7;
    
    int cnt8=min(z,x);
    ans+=cnt8,z-=cnt8,x-=cnt8;
    
    int cnt9=x/2;
    ans+=cnt9,x-=2*cnt9;
    
    int cnt10=y;
    ans+=cnt10,y=0;

    int cnt11=z;
    ans+=cnt11,z=0;

    int cnt12=x;
    ans+=cnt12,x=0;
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}