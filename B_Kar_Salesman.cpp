#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    int sum=0,temp=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
        if(temp<a[i])temp=a[i];
    }
    cout<<max((sum+x-1)/x,temp)<<endl;
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