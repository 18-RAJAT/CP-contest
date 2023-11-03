#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int i=0;
    while(i+1<n && a[i]<a[i+1])
    {
        i++;
    }
    while(i+1<n && a[i]==a[i+1])
    {
        i++;
    }
    while(i+1<n && a[i]>a[i+1])
    {
        i++;
    }
    cout<<(i==n-1?"YES":"NO")<<endl;
}
signed main()
{
    sol();
    return 0;
}