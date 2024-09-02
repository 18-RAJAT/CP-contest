#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=200005;
bool recur(int val,int x,int cnt,int k)
{
    if(k<val+1-cnt)return false;
    if(k>val+1-cnt)return true;
    return val+1-cnt<k || (val%x==0 && val/x+1>cnt)?true:false;
}
int binary_search_max_mex(int l,int r,int x,int cnt,int k)
{
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(recur(mid,x,cnt,k))l=mid+1;else r=mid-1;
    }
    return r;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    array<bool,MAX+1000>pre;
    fill(pre.begin(),pre.end(),false);
    int x=0,cnt=0;
    array<int, MAX> arr;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        x=__gcd(x,arr[i]);
        if(arr[i]==0)cnt++;
    }
    if(n==1)
    {
        cout<<(k>arr[0]?k:k-1)<<endl;
        return;
    }
    pre[0]=true;
    if(cnt==0)cnt++;
    int tmp=x;
    for(int i=1;i<=n-cnt;++i)
    {
        if(tmp<MAX+1000)pre[tmp]=1;
        tmp+=x;
    }
    int l=k-1,r=1e12;
    cout<<binary_search_max_mex(l,r,x,1+n-cnt,k)<<endl;
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