#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[51];
        int ans(0),l(0),r(n-1);
        for(int i=0;i<n;++i)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        while(l<r)
        {
            ans+=abs(arr[r]-arr[l]);
            l++;
            r--;
        }
        cout<<ans<<"\n";
    }
}