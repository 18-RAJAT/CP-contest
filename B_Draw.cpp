#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;
    long long a[n],b[n];
    long long ans=0;
    long long l,L,r,R;
    l=L=r=R=0;

    for(long long i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
        r=a[i];R=b[i];
        long long curr=max<long long>(0,min<long long>(r,R)-max<long long>(l,L)+1);
        if(a[i-1]==b[i-1] && i)
        {
            curr--;
        }
        ans+=max<long long>(curr,0);
        l=a[i];
        L=b[i];
    }
    cout<<ans<<"\n";
    return 0;
}