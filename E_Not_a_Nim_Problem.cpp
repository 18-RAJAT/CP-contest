#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
vector<int>nim(N,-1),primes(N,1);
void compute()
{
    primes[0]=0,primes[1]=1;
    nim[0]=0,nim[1]=1;
    int ans=0;
    for(int i=2;i<N;++i)
    {
        if(primes[i])
        {
            for(int j=i;j<N;j+=i)
            {
                if(nim[j]==-1)nim[j]=ans;
                primes[j]=0;
            }
            ans++;
            if(i==2)ans++;
        }
    }
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
    int ans=0;
    compute();
    for(int i=0;i<n;++i)
    {
        ans^=nim[a[i]];
    }
    cout<<(ans==0?"Bob":"Alice")<<endl;
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