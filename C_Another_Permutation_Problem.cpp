#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        for(int i=1;i<=n;++i)
        {
            s+=i*i;
        }   
        int ans=s-n*n;
        for(int i=n;i>0;--i)
        {
            s-=i*i;
            int mx=0;
            int sm=s;
            for(int j=0;j<=(n-i);++j)
            {
                mx=max<int>(mx,(i+j)*(n-j));
                sm+=(i+j)*(n-j);
            }
            sm-=mx;
            ans=max<int>(ans,sm);
        }
        cout<<ans<<"\n";
    }
}