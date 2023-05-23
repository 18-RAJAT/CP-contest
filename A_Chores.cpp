#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int q;
        cin>>q;
        if(n-k<i)
        {
            ans+=x;
        }
        else
        {
            ans+=q;
        }
    }
    cout<<ans<<"\n";
}