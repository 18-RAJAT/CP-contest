#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1),ar,br,ok;
    int sz=r-l+1;
    for(int i=1;i<=n;++i)cin>>a[i];
    int sum1=0,sum2=0;
    for(int i=1;i<=r;++i)
    {
        ar.push_back(a[i]);
    }
    for(int i=l;i<=n;++i)
    {
        br.push_back(a[i]);
    }
    // for(int i=l-1;i<r;++i)
    // {
    //     // ar.push_back(a[i]);
    //     sum+=a[i];
    // }
    // for(int i=0;i<n;++i)
    // {
    //     if(i<l-1 || i>=r)br.push_back(a[i]);
    // }
    // for(int i=0;i<l-1;++i)ar.push_back(a[i]);
    // for(int i=r;i<n;++i)br.push_back(a[i]);
    // for(int i=l-1;i<r;++i)ok.push_back(a[i]);
    sort(ar.begin(),ar.end());
    sort(br.begin(),br.end());
    // sort(ok.begin(),ok.end());
    // int m=ar.size(),k=br.size(),mn=min(m,k);
    // vector<int>s1(m+1,0),s2(k+1,0);
    //1->m,1->k
    // for(int i=1;i<=m;++i)s1[i]=s1[i-1]+ar[i-1];
    // for(int i=1;i<=k;++i)s2[i]=s2[i-1]+br[i-1];
    // int ans=sum;
    // int cnt=0,x=sum,y=sum,f=ok.size()-1,S=ar.size(),P=br.size();
    // for(;f>=0 && cnt<S;)
    // {
    //     if(ar[cnt]<ok[f])
    //     {
    //         x-=ok[f],x+=ar[cnt],cnt++,f--;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // f=ok.size()-1;
    // for(;f>=0 && cnt<P;)
    // {
    //     if(ok[f]>br[cnt])
    //     {
    //         y-=ok[f],y+=br[cnt],cnt++,f--;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // for(int k=1;k<=mn;++k)
    // {
    //     int cur=sum-s1[k]+s2[k];
    //     if(cur<ans)ans=cur;
    // }
    // int ans=min<int>(sum,min<int>(x,y));
    for(int i=0;i<sz;++i)sum1+=ar[i];
    for(int i=0;i<sz;++i)sum2+=br[i];
    int ans=min<int>(sum1,sum2);
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