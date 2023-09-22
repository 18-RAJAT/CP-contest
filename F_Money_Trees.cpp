#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<int> pref(n);
    pref[0]=a[0];
    for(int i=1;i<n;++i)
    {
        pref[i]=pref[i-1]+a[i];
    }
    int it1=0,it2=0;
    int sum=0;
    int ans=0;
    int mn=*min_element(a.begin(),a.end());
    if(mn<=k) ans=1;
    auto chk=[&](int it2,int it1)
    {
        if(it1==0) return pref[it2];
        else return pref[it2]-pref[it1-1];
    };
    while(it2<n-1)
    {
        if(b[it2]%b[it2+1]==0)
        {
            sum=chk(it2+1,it1);
            if(sum<=k)
            {
                ans=max(ans,it2+1-it1+1);
            }
            else
            {
                it1+=1;
            }
        }
        else it1=it2+1;
        it2+=1;
    }
    cout<<ans<<"\n";
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