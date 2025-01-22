#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template(build+modified bs)
vector<int>build(vector<int>& arr)
{
    int n=arr.size(),p=n/2;
    vector<int>pref(p+1,0);
    for(int i=1;i<=p;++i)pref[i]=pref[i-1]+arr[n-i]-arr[i-1];
    return pref;
}
int recur(int L,int R,int K,vector<int>& pA,vector<int>& pB)
{
    int ans=-1e18;
    while(R-L>=3)
    {
        int m1=L+(R-L)/3,m2=R-(R-L)/3;
        int f1=pA[m1]+pB[K-m1],f2=pA[m2]+pB[K-m2];
        (f1<f2)?L=m1+1:R=m2-1;
    }
    for(int i=L;i<=R;++i)ans=max(ans,pA[i]+pB[K-i]);
    return ans;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int>pA=build(a),pB=build(b);
    int x=pA.size()-1,y=pB.size()-1,mn=min((n+m)/3,x+y);
    vector<int>dp(mn+1,-1e18);
    dp[0]=0;
    for(int k=1;k<=mn;++k)
    {
        int L=max(0LL,max(2*k-m,k-y)),R=min(k,min(n-k,x));
        if(L<=R)dp[k]=recur(L,R,k,pA,pB);
    }
    int ans=0;
    for(int k=1;k<=mn;++k)if(dp[k]>=0)ans=k;
    cout<<ans<<endl;
    if(ans>=1)
    {
        for(int k=1;k<=ans;++k)cout<<max(0LL,dp[k])<<(k+1<=ans?" ":"\n");
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