#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n,t;
    cin>>n>>t;
    long long int a[n],b[n];
    for(auto& it:a)
    {
        cin>>it;
    }
    for(auto& it:b)
    {
        cin>>it;
    }
    long long int ans=-1;
    for(int i=0;i<n;i++)
    {
        long long int tsp=t-i;
        if(a[i]<=tsp)
        {
            if(ans==-1 or b[ans-1]<b[i])
            {
                ans=i+1;
            }
        }
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
