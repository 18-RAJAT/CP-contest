#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int temp=4*n-2;
    if(k==temp)
    {
        cout<<temp/2+1<<endl;
    }
    else
    {
        (k%2==0)?(cout<<k/2<<endl):(cout<<k/2+1<<endl);
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