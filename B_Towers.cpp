#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    array<array<int,2>,1000>a; 
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0];
        a[i][1]=i;
    }
    int m=k;
    vector<array<int,2>> ans;
    for(int i=0;i<k;++i)
    {
        sort(a.begin(),a.begin()+n);
        if(a[n-1][0]>a[0][0]+1)
        {
            ans.push_back({a[n-1][1],a[0][1]});
            a[0][0]++,a[n-1][0]--;
        }
    }
    sort(a.begin(),a.begin()+n);
    cout<<a[n-1][0]-a[0][0]<<" "<<ans.size()<<endl;
    for(auto& it:ans)cout<<it[0]+1<<" "<<it[1]+1<<endl;
}
signed main()
{
    sol();
    return 0;
}