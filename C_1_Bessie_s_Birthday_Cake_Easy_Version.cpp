#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    array<int,2>arr[x];
    for(int i=0;i<x;++i)
    {
        cin>>arr[i][0];
        arr[i][1]=i;
    }
    sort(arr,arr+x);
    int Last=x-2;
    for(int i=0;i<x-1;++i)
    {
        if(arr[i][0]+2==arr[i+1][0])
        {
            Last++;
        }
    }
    int First=arr[0][0];
    if((arr[x-1][0]+2)%n==First && x>1)
    {
        Last++;
    }
    cout<<Last<<endl;
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