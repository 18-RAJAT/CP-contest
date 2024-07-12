#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>arr{a,b,c};
    for(int i=0;i<5;++i)
    {
        sort(arr.begin(),arr.end());
        arr[0]++;
    }
    cout<<arr[0]*arr[1]*arr[2]<<endl;
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