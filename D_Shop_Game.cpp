#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    priority_queue<int>pq;
    for(int i=0;i<n;++i)
    {
        pq.push(a[i]-b[i]);
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(i<k)
        {
            ans+=a[i];
        }
        else
        {
            ans+=max(a[i],a[i]-pq.top());
            pq.pop();
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