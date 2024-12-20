#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int l=1,r=n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        if((i+1)%k==0)
        {
            a[i]=l++;
        }
        else a[i]=r--;
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