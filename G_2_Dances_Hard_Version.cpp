#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a,b(n);
    a.push_back(1);
    for(int i=1;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans=0,j=0;
    for(int i=0;i<n;++i)
    {
        while(j<n)
        {
            if(a[i]<b[j])
            {
                ans++;
                j++;
                break;
            }
            j++;
        }
    }
    cout<<n-ans<<endl;
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