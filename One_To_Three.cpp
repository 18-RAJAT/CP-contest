#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+2,0);
    int ans=0;
    for(int i=1;i<=n;++i)cin>>a[i],ans+=a[i];
    queue<int>q;
    vector<int>chk(n+2,0);
    for(int i=2;i<=n-1;++i)
    {
        if(a[i]==3 && (a[i-1]+a[i+1])==4)
        {
            q.push(i);
            chk[i]=1;
        }
    }
    while(!q.empty())
    {
        int i=q.front();q.pop();
        chk[i]=0;
        // ans-=2;
        if(a[i]==3 && (a[i-1]+a[i+1])==4)
        {
            // a[i]=1;
            a[i]=4-a[i],ans-=2;
            for(auto j:{i-1,i+1})
            {
                if(j>=2 && j<=n-1)
                {
                    if(a[j]==3 && (a[j-1]+a[j+1])==4 && !chk[j])
                    {
                        q.push(j);
                        chk[j]=1;
                    }
                }
            }
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