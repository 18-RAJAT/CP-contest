#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    int prefix[n],suffix[n];
    memset(prefix,0,sizeof(prefix));
    memset(suffix,0,sizeof(suffix));

    prefix[0]=array[0];
    for(int i=1;i<n;++i)
    {
        prefix[i]=max<int>(prefix[i-1],array[i]+i);
    }
    suffix[n-1]=array[n-1]-n+1;
    for(int i=n-2;i>=0;--i)
    {
        suffix[i]=max<int>(suffix[i+1],array[i]-i);
    }
    int ans=0;
    for(int i=1;i+1<n;++i)
    {
        ans=max<int>(ans,prefix[i-1]+array[i]+suffix[i+1]);
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