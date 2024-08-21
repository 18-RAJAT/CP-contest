#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(auto& i:a)cin>>i;
    vector<int>arr(n+1,0);
    for(auto& it:a)arr[it]++;
    int ans=n-(*max_element(arr.begin(),arr.end()));
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