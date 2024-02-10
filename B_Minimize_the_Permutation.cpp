#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],traverse[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i],traverse[i]=0;
    }
    for(int i=0;i<n-1;++i)
    {
        int j=0;
        while(j<n && a[j]!=i+1)
        {
            j++;
        }
        while(j>=1 && !traverse[j] && a[j]<a[j-1])
        {
            swap(a[j],a[j-1]);
            traverse[j]=1;
            j--;
        }
    }
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