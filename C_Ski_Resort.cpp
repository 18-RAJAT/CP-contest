#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while (t-->0)
    {
        long long int n,k,q;
        cin>>n>>k>>q;

        long long int cons=0;
        vector<long long int>a(n);
        long long int ans=0;
        for(auto&it:a)
        {
            cin>>it;
            if(it<=q)cons++;
            else cons=0;
            long long int vals=cons-k+1;
            ans+=max<long long int>(vals,0LL);
        }
        cout<<ans<<"\n";
    }
}