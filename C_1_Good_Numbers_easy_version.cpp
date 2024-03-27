#include<bits/stdc++.h>
using namespace std;
#define int long long
int binary_exponentiation(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    int res=binary_exponentiation(a,b/2);
    if(b%2==0)
    {
        return res*res;
    }
    return a*binary_exponentiation(a,b-1);
}
void sol()
{
    int n;
    cin>>n;
    int res=0,power=0;
    while(res<n)
    {
        res+=binary_exponentiation(3,power);
        power++;
    }
    power--;
    for(int i=power;~i;--i)
    {
        int exp=binary_exponentiation(3,i);
        if(res-exp>=n)
        {
            res-=exp;
        }
    }
    cout<<res<<endl;
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