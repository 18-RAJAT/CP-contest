#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int res=n+m,ans=INT_MAX;
    for(int i=0;i<m;++i)
    {
        int temp=i;
        for(int j=0;j<n;++j)
        {
            if(m==temp)break;
            if(a[j]==b[temp])temp++;
        }
        ans=min(ans,res-(temp-i));
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