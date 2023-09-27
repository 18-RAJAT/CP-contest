#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>segment;
void build(int s,int e,int i,vector<int>&a)
{
    if(s==e)
    {
        segment[i]=a[s];
        return;
    }
    int mid=s+(e-s)/2;
    build(s,mid,2*i+1,a);//left
    build(mid+1,e,2*i+2,a);//right
    segment[i]=segment[2*i+1]&segment[2*i+2];
    // segment[i]=min(segment[2*i+1],segment[2*i+2]);//with bit
}
int RangeQuery(int s,int e,int i,int QueryStart,int QueryEnd)
{
    if(QueryStart<=s&&QueryEnd>=e)
    {
        return segment[i];
    }
    if(QueryStart>e||QueryEnd<s)
    {
        return INT_MAX;
    }
    int mid=s+(e-s)/2;
    int l=RangeQuery(s,mid,2*i+1,QueryStart,QueryEnd);//left
    int r=RangeQuery(mid+1,e,2*i+2,QueryStart,QueryEnd);//right
    return l&r;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    segment.resize(4*n);//4*n is the maximum size of segment tree
    build(0,n-1,0,a);
    while(q--)
    {
        int st,k;
        cin>>st>>k;
        st--;
        int h=n-1;
        int l=st;
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int qr=RangeQuery(0,n-1,0,st,mid);
            if(qr>=k)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        if(ans>=0)
        {
            ans++;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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