#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    string ans="";
    sort(a.begin(),a.end(),[&](array<int,2>&x,array<int,2>&y)
    {
        if(min(x[0],x[1])!=min(y[0],y[1]))
        return min(x[0],x[1])<min(y[0],y[1]);
        return max(x[0],x[1])<max(y[0],y[1]);
    });
    for(int i=0;i<n;++i)
    {
        ans+=to_string(a[i][0])+" "+to_string(a[i][1])+" ";
    }
    ans.pop_back();
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