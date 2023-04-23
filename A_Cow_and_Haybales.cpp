#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n,d;
    cin>>n>>d;
    int haybale[n+1];
    memset(haybale,0,sizeof(haybale));

    int ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>haybale[i];
    }
    for(int i=1;i<=n;++i)
    {
        int first=haybale[i];
        int second=i-1;

        if(d<first*second)
        {
            ans+=(d/second);
            break;
        }
        ans+=first;
        d-=first*second;
    }
    cout<<ans<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}