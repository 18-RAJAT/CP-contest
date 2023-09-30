#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    if(a>b)
    {
        cout<<n;
    }
    else
    {
        sort(arr,arr+n);
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            if(arr[i]<=a)
            {
                cnt++;
            }
        }
        cout<<(cnt+1)/2;
    }
}
signed main()
{
    sol();
    return 0;
}