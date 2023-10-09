#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int power(int x,int y,int mod)
{
    int res=1;
    x=x%mod;
    while(y>0)
    {
        if(y&1)
        {
            res=(res*x)%mod;
        }
        y=y>>1;
        x=(x*x)%mod;
    }
    return res;
}
int sqrt(int x)
{
    int l=1;
    int r=x;
    int ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(mid*mid<=x)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}
int inv(int x,int mod)
{
    return power(x,mod-2,mod);
}
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vp(n);
    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        vp.push_back({-t,i});
    }
    sort(vp.begin(),vp.end());
    vector<int>done(n,0);
    
    done.resize(n+1);
    
    int count=0;
    int ans=0;
    int it=0;
    while(count<n && it<=n)
    {
        int tmp=vp[it].second;
        //if tmp is already done then skip it.
        if(done[tmp])
        {
            it++;
            continue;
        }
        int ctr=0;
        for(int i=1;i<=sqrt(tmp);++i)
        {
            if(tmp%i==0)
            {
                //i is a factor of tmp.
                if(!done[i])
                {
                    ctr++;
                    done[i]=1;
                    count++;
                }
                //if i is a factor of tmp then tmp/i is also a factor of tmp.
                if(!done[tmp/i])
                {
                    done[tmp/i]=1;
                    ctr++;
                    count++;
                }
            }
        }
        int a=n-count;//number of elements which are not divisible by tmp.
        int b=power(2,ctr,mod)-1;//number of subsets of ctr elements.
        int d=power(2,a,mod);//number of subsets of a elements.

        d%=mod;
        b%=mod;

        ans+=((-vp[it].first)*((b*d)%mod))%mod;//number of subsets of a elements which are divisible by tmp.
        // int c=inv(power(2,ctr,mod),mod);//number of subsets of ctr elements which are not divisible by tmp.
        ans%=mod;
        it++;
    }
    cout<<ans%mod<<"\n";
}
signed main()
{
    sol();
    return 0;
}