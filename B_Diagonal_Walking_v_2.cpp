#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        long long int n,m,k;
        cin>>n>>m>>k;
        long long int minimumMoves=abs(n-m)+min<long long int>(n,m);

        if(k<minimumMoves)
        {
            cout<<"-1"<<"\n";
            continue;
        }
        long long int A=abs(n-m)&1;
        long long int B=(k-min(n,m))&1;

        if(A and B)
        {
            cout<<k-1<<"\n";
        }
        if(not A and B)
        {
            cout<<k-2<<"\n";
        }
        if(A and not B)
        {
            cout<<k-1<<"\n";
        }
        if(not A and not B)
        {
            cout<<k<<"\n";
        }
    }
    return 0;
}