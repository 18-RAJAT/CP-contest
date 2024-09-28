#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int Pairs=i,Segment=n-i-1;
        int total=Pairs+Segment+Pairs*Segment;
        mp[total]++;
        if(i!=n-1)
        {
            int diff=a[i+1]-a[i]-1;
            mp[Segment+Pairs*Segment]+=diff;
        }
    }
    for(int i=0;i<q;++i)
    {
        int k;
        cin>>k;
        cout<<mp[k]<<" ";
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