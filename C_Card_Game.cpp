#include<bits/stdc++.h>
using namespace std;

const int N=200;
long long int fact[N];
void sol()
{
    auto pw=[&](long long int a,long long int b)->long long int
        {
            a%=998244353;
            long long int res=1;
            while(b)
            {
                if(b&1)
                {
                    res*=a;
                    res%=998244353;
                }
                a*=a;
                a%=998244353;
                // b>>=1;
                b/=2;
            }
            return res;
        };
        auto calc=[&](long long int n,long long int k)->long long int
        {
            return (fact[n]*pw(fact[n-k]*fact[k],998244353-2))%998244353;
        };


        long long int n;
        cin>>n;

        long long int ans1,ans2;
        ans1=ans2=0;

        for(long long int i=n;i>=2;i-=2)
        {
            if(i%4==n%4)
            {
                ans1+=calc(i-1,i/2);
                ans2+=calc(i-2,i/2);
            }
            // ans1+=calc(i,1);
            // ans2+=calc(i,2);
            else
            {
                ans2+=calc(i-1,i/2);
                ans1+=calc(i-2,i/2);
            }
            ans1%=998244353;
            ans2%=998244353;
        }
        cout<<ans1<<" "<<ans2<<" "<<"1"<<"\n";
}

int main()
{
    fact[0]=1;
    for(long long int i=1;i<N;++i)
    {
        fact[i]=(fact[i-1]*i)%998244353;
    }
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        sol();
    }
}