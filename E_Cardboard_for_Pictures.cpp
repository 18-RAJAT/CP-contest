#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
        function<bool(long long,vector<long long>&,long long,long long)>calc=[&](long long mid,vector<long long>&left,long long n,long long m)
        {
            long long current(0);
            for(long long i=0;i<n;++i)
            {
                current+=left[i]*left[i]+2*left[i]*mid*2+mid*mid*4;

                if(m<current)
                {
                    return false;
                }
            }
            return true;
        };
        long long n,c;
        cin>>n>>c;
        vector<long long>left(n);
        long long ans;
        long long x(0),y(0);
        for(long long i=0;i<n;++i)
        {
            cin>>left[i];
        }
        long long low(1),high(1e9);
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(calc(mid,left,n,c))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<ans<<"\n";
    }
}