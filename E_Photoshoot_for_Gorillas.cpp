#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N=2e5+5;
void sol()
{
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    vector<int>a(w);
    for(int i=0;i<w;++i)
    {
        cin>>a[i];
    }
    vector<int>arr;
    for(int i=0;i<n;++i)
    {
        int l=max(0LL,k-i-1);
        int r=max(0LL,k-(n-i));
        for(int j=0;j<m;++j)
        {
            int L=max(0LL,k-j-1);
            int R=max(0LL,k-(m-j));
            int gorilla=(k-l-r)*(k-L-R);
            arr.push_back(gorilla);
        }
    }
    assert(arr.size()==n*m);
    sort(arr.begin(),arr.end());
    reverse(arr.begin(),arr.end());
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<w;++i)ans+=a[i]*arr[i];
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