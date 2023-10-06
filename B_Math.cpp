#include<bits/stdc++.h>
using namespace std;
#define int long long
int call(int n)
{
    int l=0,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(mid*mid<=n)
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

int check(int n)
{
    int cnt=0;
    int sq=call(n);
    if(sq*sq==n)
    {
        if(sq!=n)
        {
            cnt++;
        }
        return sq;
    }
    int temp=n;
    int ert=0;
    //using this we can find prime factorization of n in O(sqrt(n))
    unordered_map<int,int>mp;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                mp[i]++;
                ert++;
            }
        }
    }
    if(n)
    {
        mp[n]++;
        ert=max(ert,mp[n]);//if n is prime then it will be 1 else it will be greater than 1
    }

    int ans=1;
    ert+=(ert&1);//if even then make it odd to make it perfect square
    for(auto& it:mp)
    {
        // cout<<it.first<<" "<<it.second<<endl;
        for(int i=0;i<ert-it.second;++i)//make it perfect square
        {
            ans*=it.first;//multiply with prime number to make it perfect square
        }
    }
    if(ans!=temp)
    {
        cnt+=2;//if not perfect square then multiply with prime number to make it perfect square
    }
    ans*=temp;
    ans=call(ans);//find square root of perfect square
    return ans;//prefect
}
void sol()
{
    int n;
    cin>>n;
    int ans=check(n);
    int m=n;
    while(ans!=n)
    {
        n=ans;
        ans=check(n);//find square root of perfect square
    }
    ans=0;
    int tmp=n;
    while(tmp<m)
    {
        tmp*=tmp;
        ans++;
    }
    if(tmp%m)
    {
        ans+=3;
    }
    // else if(n>=3)
    // {
    //     n+=2;
    // }
    else if(m!=tmp)
    {
        ans++;
    }
    cout<<n<<" "<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}