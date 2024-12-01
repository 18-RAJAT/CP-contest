#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        auto cmp=[](int a,int b)
        {
            while(b!=0)
            {
                int temp=b;
                b=a%b;
                a=temp;
            }
            return a;
        };
        int gcd=cmp(a,b);
        int lcm=(a*b)/gcd;
        cout<<lcm<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}