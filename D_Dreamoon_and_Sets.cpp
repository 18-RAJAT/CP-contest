#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    cout<<(6*(n-1)+5)*k<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<(6*i+1)*k<<" "<<(6*i+2)*k<<" "<<(6*i+3)*k<<" "<<(6*i+5)*k<<" "<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}