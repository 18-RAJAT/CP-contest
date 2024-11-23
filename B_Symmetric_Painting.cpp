#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    while(b)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    if(2*k==n)
    {
        cout<<"No"<<endl;
    }
    else
    {
        int G=gcd(k,n);
        if(G>1)
        {
            if((n/G)%2==0) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        else cout<<"Yes"<<endl;
    }
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