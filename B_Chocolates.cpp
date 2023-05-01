#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    memset(a,0,sizeof(a));
    for(long long int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    long long int ans=0,curr;
    curr=a[n-1];
    ans+=a[n-1];
    for(long long int i=n-2;i>=0;--i)
    {
        if(curr==0)
        {
            continue;
        }
        curr=min<long long int>(curr-1,a[i]);
        ans+=curr;
    }
    cout<<ans;
}