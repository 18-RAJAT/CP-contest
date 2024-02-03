#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>prefix(n);
    int sum=0;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        prefix[i]=sum;
        mp[sum]=1;
    }
    mp[0]=1;
    int ans=n-1;
    int last=prefix[n-1];
    for(int i=1;i<=last;++i)
    {
        if(last%i==0)
        {
            int ele=0;
            int here=last;
            bool ok=true;
            while(here>0)
            {
                here-=i;
                if(mp[here]!=1)
                {
                    ok=false;
                    break;
                }
                ele++;
            }
            int tmp=n-ele;
            if(tmp>=0 && ok)
            {
                ans=min(ans,tmp);
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