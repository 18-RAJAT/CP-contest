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
    int i=0,j=n-1,ans=n;
    while(i<j)
    {
        if(arr[i]+arr[j]==INT_MAX)
        {
            ans--;
            i++;
            j--;
        }
        else
        {
            (arr[i]+arr[j]>INT_MAX?j--:i++);
        }
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