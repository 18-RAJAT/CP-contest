#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=0;i<p;++i)
    {
        int x;
        cin>>x;
        if(n&1)
        {
            cout<<(x>=n-k+1?'X':'.');
        }
        else
        {
            if(x>=n-(2*(k-1)))
            {
                cout<<(x&1?'.':'X');
            }
            else
            {
                cout<<'.';
            }
            if(k>n/2 && (x&1) && (x+1)/2>n-k)
            {
                cout<<'X';
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}