#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x;
    cin>>x;
    int n=1,f=1;
    while(f<x)
    {
        n++,f*=n;
    }
    cout<<n<<endl;
}
signed main()
{
    sol(); 
    return 0;
}