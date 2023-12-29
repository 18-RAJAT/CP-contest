#include<bits/stdc++.h>
using namespace std;
#define int long long
int compute[200005];
void sol()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
    }
    int cnt=0,ok=0;
    for(int i=0;i<n;++i)
    {
        for(int j=2;j<=200005;j*=2)
        {
            if(mp[j-a[i]]>0)
            {
                if(a[i]==j-a[i])
                {
                    if(mp[j-a[i]]>1 && compute[a[i]]==0)
                    {
                        compute[a[i]]=1;
                        ok=1;
                        break;
                    }
                    else if(mp[j-a[i]]>1 && compute[a[i]]==1)
                    {
                        ok=1;
                        break;
                    }
                    else if(mp[j-a[i]]==1)
                    {
                        ok=1;
                        break;
                    }
                }
                else
                {
                    ok=1;
                    break;
                }
            }
        }
        cnt=ok-cnt;
        if(ok && compute[a[i]]==0)
        {
            cnt++;
            ok=0;
        }
    }
    if(cnt<=1)
    {
        cout<<cnt+1<<endl;
        return;
    }
    cout<<cnt<<endl;
}
signed main()
{
    sol();
    return 0;
}