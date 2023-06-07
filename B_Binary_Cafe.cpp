#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        long long int n,k;
        cin>>n>>k;
        k=min<long long int>(k,32LL);
        long long int ans=min<long long int>(n+1,1LL<<k);
        cout<<ans<<"\n";       
    }
    return 0;
}