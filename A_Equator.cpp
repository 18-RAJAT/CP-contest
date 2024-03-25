#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int sum=accumulate(a.begin(),a.end(),0LL);
    int current=0;
    for(int i=0;i<n;++i)
    {
        current+=a[i];
        if(current>=ceil(sum/2.0))
        {
            cout<<i+1<<endl;
            return;
        }
    }
}
signed main()
{
    sol();
    return 0;
}