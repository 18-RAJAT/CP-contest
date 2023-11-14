#include<bits/stdc++.h>
using namespace std;
#define int long long

int pythagoreanTriple(int n)
{
    if(n<=2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    else
    {
        if(n%2&1)
        {
            int l=((n*n)-1)/2;
            int r=((n*n)+1)/2;
            cout<<l<<" "<<r<<endl;
        }
        else
        {
            n/=2;
            int l=((n*n)-1);
            int r=((n*n)+1);
            cout<<l<<" "<<r<<endl;
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    pythagoreanTriple(n);
}
signed main()
{
    sol();
    return 0;
}