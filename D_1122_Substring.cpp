#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    auto recur=[&](int x)->int
    {
        vector<int>cnt(n+1,-1);
        int l=0,ans=0;
        for(int p=x;p+1<n;p+=2)
        {
            if(a[p]!=a[p+1])
            {
                l=(p/2)+1;
                continue;
            }
            int y=a[p],cur=(p/2);
            if(cnt[y]>=l)
            {
                l=cnt[y]+1;
            }
            cnt[y]=cur;
            int sza=(cur-l+1)*2;
            ans=max(ans,sza);
        }
        return ans;
    };
    cout<<max(recur(0),recur(1))<<endl;
}
signed main()
{
    sol();
    return 0;
}