#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int ans=n*(n+1)/2;//sum of n natural numbers
    int ok=ans-sum;//calculate the missing number
    a.push_back(ok);
    k%=(n+1);
    k-=(n+1);//k=1

    // vector<int>res;
    for(int i=0;i<n;++i)
    {
        // res.push_back(a[(i+k+n+1)%(n+1)]);
        cout<<(a[(i-k)%(n+1)])<<" ";//(i+k+n+1)%(n+1)
    }
    cout<<endl;
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