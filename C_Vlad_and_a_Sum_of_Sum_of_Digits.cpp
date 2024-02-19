#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=1;i<=n;++i)
    {
        arr.push_back(i);
    }
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int sum=0;
        while(arr[i]>0)
        {
            sum+=arr[i]%10;
            arr[i]/=10;
        }
        ans.push_back(sum);
    }
    int result=0;
    for(int i=0;i<ans.size();++i)
    {
        result+=ans[i];
    }
    cout<<result<<endl;
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