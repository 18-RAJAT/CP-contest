#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
// int NCR(int n,int r)
// {
//     int ans=1;
//     for(int i=1;i<=r;++i)
//     {
//         ans*=(n-i+1);
//         ans/=i;
//     }
//     return ans;
// }

int NC2(int x)//calculate xC2 or xC2=x*(x+1)/2
{
    return (x*(x+1))/2;
}
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    int L=lcm(x,y);//2,3=6 6,3=6 6,2=6

    x=n/x;//calculate how many x in n
    y=n/y;//calculate how many y in n
    L=n/L;//calculate how many L in n

    x-=L;//remove L from x because L is LCM of x and y
    y-=L;//vice versa above

    // int NC=NCR(L,2);//calculate how many L in nC2

    int ans=NC2(n)-NC2(y)-NC2(n-x)-NC2(0);//calculate how many L in nC2 and remove it from nC2 and remove xC2 and remove yC2 and remove 0C2.
    cout<<ans<<endl;
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