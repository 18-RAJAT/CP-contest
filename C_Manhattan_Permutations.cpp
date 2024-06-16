#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)a[i]=i+1;
    int i=0,j=n-1;
    for(;i<=j;)
    {
        int diff=2*abs(a[i]-(j+1));
        if(diff<=k)
        {
            swap(a[i],a[j]),k-=diff,i++,j--;
        }
        else j--;
    }
    if(k!=0)
    {
        cout<<"NO"<<endl;return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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