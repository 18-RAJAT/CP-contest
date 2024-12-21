#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=1;
    for(int k=1;k<n;++k)
    {
        for(int i=0;i+k<n;++i)
        {
            int cnt=1,cur=a[i];
            for(int j=i+k;j<n;j+=k)
            {
                if(a[j]==cur)
                {
                    cnt++,cur=a[j];
                }
                else break;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}