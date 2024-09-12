#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    pair<int,int>matrix[n*n];
    int a=0,b=n/2;
    for(int i=0;i<n*n;++i)
    {
        matrix[i]=pair<int,int>(a,b);
        (n-1==i%n&1)?a=(1+a)%n:(a=(a+n-1)%n,b=(1+b)%n);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            pair<int,int>* it=matrix+(n*i+j);
            int row=it->first,col=it->second;
            cout<<(row*n+col+1)<<(j+1==n?"\n":" ");
        }
    }
}
signed main()
{
    sol();
    return 0;
}