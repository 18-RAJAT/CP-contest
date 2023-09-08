#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MEX=1e5+5;
vector<int>prime;
vector<bool>primes(MEX,true);

void sol()
{
    for(int i=2;i*i<MEX;++i)
    {
        if(primes[i])
        {
            for(int j=i*i;j<MEX;j+=i)
            {
                primes[j]=false;
            }
        }
        else
        {
            continue;
        }
    }
    /*
        gcd(a,b)=1 or gcd(a,b)=0.coPrime
        gcd(6,9)=3 not coPrime -> gcd(6,9)!=1 or gcd(6,9)!=0
        gcd(8,9)=1 coPrime -> gcd(8,9)==1 or gcd(8,9)==0
    */
    prime.push_back(2);//2 is prime
    for(int i=3;i<MEX;i+=2)//i+=2 because even number is not prime
    {
        if(primes[i])
        {
           prime.push_back(i);
        }
    }
}
signed main()
{
    sol();
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        bool flag=false;
        for(int i=l;i<=r;++i)
        {
            // if(primes[i])
            // {
            //     cout<<i<<" ";
            //     flag=true;
            //     break;
            // }
            for(auto&it:prime)
            {
                if(i%it==0)
                {
                    if(it!=i)
                    {
                        cout<<i-it<<" "<<it<<endl;
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}