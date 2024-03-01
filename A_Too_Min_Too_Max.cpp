#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<<abs(arr[0]-arr[n-2])+abs(arr[n-2]-arr[1])+abs(arr[1]-arr[n-1])+abs(arr[n-1]-arr[0])<<endl;
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