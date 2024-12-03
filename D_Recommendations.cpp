#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,3>>a(n);
    set<int>st;
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1],a[i][2]=i;
        mp[{a[i][0],a[i][1]}]++;
    }
    //first [0]
    sort(a.begin(),a.end(),[&](auto a,auto b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    });
    vector<int>dp(n),ndp(n);
    for(int i=0;i<n;++i)
    {
        auto LB=st.lower_bound(a[i][1]);
        (LB==st.end())?ndp[a[i][2]]=-1:ndp[a[i][2]]=*LB;
        st.insert(a[i][1]);
    }
    //second [1]
    sort(a.begin(),a.end(),[&](auto a,auto b)
    {
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]>b[1];
    });
    st.clear();
    for(int i=0;i<n;++i)
    {
        auto UB=st.upper_bound(a[i][0]);
        (UB==st.begin())?dp[a[i][2]]=-1:dp[a[i][2]]=*prev(UB);
        st.insert(a[i][0]);
    }
    //third [3]
    sort(a.begin(),a.end(),[&](auto a,auto b)
    {
        return a[2]<b[2];
    });
    for(int i=0;i<n;++i)
    {
        cout<<((mp[{a[i][0],a[i][1]}]>=2 || (dp[i]==-1 || ndp[i]==-1))?0:ndp[i]-dp[i]+1-(a[i][1]-a[i][0]+1))<<endl;
    }
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