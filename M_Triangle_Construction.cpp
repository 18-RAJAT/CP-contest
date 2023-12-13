#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0,maximum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        maximum=max<int>(maximum,a[i]);
        sum+=a[i];
    }
    cout<<min<int>(sum/3,abs<int>(sum-maximum));
}
signed main()
{
    sol();
    return 0;
}