#include<bits/stdc++.h>
using namespace std;
#define int long long
int GCD(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return GCD(b,a%b);
}
void sol()
{
    int a,b;
    cin>>a>>b;
    int total=a*b/GCD(a,b);
    if(a<b)
    {
        swap(a,b);
    }
    cout<<((total==a)?a*(a/b):total)<<endl;
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