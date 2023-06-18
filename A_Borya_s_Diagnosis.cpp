#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,d,ans=0;cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>s>>d;
        while(s<=ans)
        {
            s+=d;
        }
        ans=s;
    }
    cout<<ans<<"\n";
}