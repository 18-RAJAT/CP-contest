#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+15;
int arr[N];
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    int ans=0;
    int unique_ele=unique(arr+1,arr+n+1)-arr-1;
    for(int i=1,j=0;i<=unique_ele;++i)
    {
        while(j<unique_ele && arr[j+1]<arr[i]+n)
        j++;
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
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