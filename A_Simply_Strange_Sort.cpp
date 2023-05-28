#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
    cin>>n;
    int a[n+1];
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    while(not is_sorted(a+1,a+n+1))
    {
        ans+=1;
        for(int j=2-ans%2;j<=n-1;j+=2)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    cout<<ans<<"\n";
}


int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
}