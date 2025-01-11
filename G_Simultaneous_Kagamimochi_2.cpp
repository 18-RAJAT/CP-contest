#include<bits/stdc++.h>
using namespace std;
#define int long long
//Rajat joshi template
vector<vector<int>>BuildSparseTable(vector<int>& ar,int n)
{
    int lg=0;
    while((1<<lg)<=n)lg++;
    vector<vector<int>>st(lg,vector<int>(n));
    for(int i=0;i<n;++i)st[0][i]=ar[i];
    for(int k=1;k<lg;++k)
    {
        for(int i=0;i+(1<<k)<=n;++i)
        {
            st[k][i]=max(st[k-1][i],st[k-1][i+(1<<(k-1))]);
        }
    }
    return st;
}
int Query(vector<vector<int>>& st,vector<int>& table,int l,int r)
{
    int k=table[r-l+1];
    return max(st[k][l],st[k][r-(1<<k)+1]);
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>j(n,n);
    /*
        j[i]<=r-l-2k+1 for i bel =>> [l,l+k-1] 
        and i guess->>
        j[i]=min(k | k>=i and a[k]>=2*a[i],else n)
    */
    for(int i=0;i<n;++i)
    {
        int res=2*a[i],LB=lower_bound(a.begin()+i+1,a.end(),res)-a.begin();
        if(LB<n)j[i]=LB;
    }
    //sp and table pre
    vector<int>ar(n),table(n+1,0);
    for(int i=0;i<n;++i)ar[i]=j[i]-i;
    for(int i=2;i<=n;++i)table[i]=table[i/2]+1;
    vector<vector<int>>st=BuildSparseTable(ar,n);
    int q;
    cin>>q;
    vector<int>ans(q);
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int m=r-l+1,tot=m/2;
        if(tot==0)
        {
            ans[i]=0;
            continue;
        }
        int L=0,R=tot;
        while(L<R)
        {
            int mid=L+(R-L+1)/2;
            if(l+mid-1>=n)
            {
                R=mid-1;
                continue;
            }
            // cout<<l<<" "<<l+mid-1<<endl;
            // for(int i=l;i<=l+mid-1;++i)cout<<a[i]<<" ";
            int ok=Query(st,table,l,l+mid-1);
            // cout<<"pos -> "<<ok<<" -> "<<table[ok]<<endl;
            (ok<=(r-mid+1)-l)?L=mid:R=mid-1;
        }
        ans[i]=L;
    }
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<endl;
}
signed main()
{
    sol();
    return 0;
}