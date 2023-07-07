#include<bits/stdc++.h>
using namespace std;

void sol()
{
    auto sqrt=[](long long n)->long long
    {
        long long x=n,y=(x+1)/2;
        while(y<x)
        {
            x=y;
            y=(x+n/x)/2;
        }
        return x;
    };
    auto pow=[](long long a,long long b)->long long
    {
        long long ans=1;
        while(b>0)
        {
            if(b&1)
            {
                ans*=a;
            }
            a*=a;
            b>>=1;
        }
        return ans;
    };
    long long n;
    cin>>n;
    for(int i=2;i<=sqrt(n);++i)
    {
        long long cnt=1;
        // while(n%i==0)
        // {
        //     n/=i;
        //     cnt++;
        // }
        while(pow(i,cnt-1)<=n)
        {
            cnt++;
        }
        for(int j=1;j<=cnt+1;++j)
        {
            long long m=(pow(i,j)-1)/(i-1);
            if(m==n)
            {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}