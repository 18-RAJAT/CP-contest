#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,int>mp1,mp2,check;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        mp2[b[i]]++;
        check[b[i]]=1;
    }
    int cnt=0,ans=0;
    for(int i=0;i<m;i++)
    {
        mp1[a[i]]++;
        if(check[a[i]] && mp1[a[i]]<=mp2[a[i]])
        {
            cnt++;
        }
    }
    if(cnt>=k)
    {
        ans++;
    }
    for(int i=1;i<=n-m;i++)
    {
        mp1[a[i-1]]--;
        mp1[a[i+m-1]]++;
        if(a[i-1]!=a[i+m-1])
        {
            if(check[a[i-1]] && mp1[a[i-1]]<mp2[a[i-1]])
            {
                cnt--;
            }
            if(check[a[i+m-1]] && mp1[a[i+m-1]]<=mp2[a[i+m-1]])
            {
                cnt++;
            }
        }
        if(cnt>=k)
        {
            ans++;
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