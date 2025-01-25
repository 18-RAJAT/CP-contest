#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=1;i<n-1;++i)
    {
        if(a[i]*a[i]!=a[i-1]*a[i+1])
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
signed main()
{
    sol();
    return 0;
}