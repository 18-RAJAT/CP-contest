#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    long long int count=0;
    // function<void(long long int)>find=[&](long long int p)->void
    // {
    //     cout<<p+2<<"\n";
    //     return;
    // };
    function<long long int(long long int)>countDivisors=[&](long long int n)->long long int
    {
        for(long long int i=1;i<=sqrt(n);++i)
        {
            if(n%i==0)
            {
                // return ((n/i==i)?count+=1:count+=2);
                if(n/i==i)
                {
                    count+=1;
                }
                else
                {
                    count+=2;
                }
            }
        }
        return count;
    };
    function<long long int(long long int,long long int)>GCD=[&](long long int a,long long int b)->long long int
    {
        if(b==0)
        {
            return a;
        }
        return GCD(b,a%b);
    };
    memset(a,0,sizeof(a));
    for(long long int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    long long int temp=a[0];
    for(long long int i=1;i<n;++i)
    {
        temp=GCD(temp,a[i]);
    }
    long long int ans=countDivisors(temp);
    cout<<ans<<"\n";
}