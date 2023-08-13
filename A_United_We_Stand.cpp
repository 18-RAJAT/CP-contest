#include<bits/stdc++.h>
using namespace std;
int a[10001];
void sol()
{
        int n;
        cin>>n;
        int mx=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            mx=max<int>(mx,a[i]);
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]==mx)
            {
                ans++;
            }  
        }
            if(ans==n)
            {
                cout<<"-1\n";
                return;
            }
            else
            {
                cout<<n-ans<<" "<<ans<<"\n";
                for(int i=1;i<=n;++i)
                {
                    if(a[i]!=mx)
                    {
                        cout<<a[i]<<" ";
                    }
                }
                cout<<"\n";
                for(int i=1;i<=n;++i)
                {
                    if(a[i]==mx)
                    {
                        cout<<a[i]<<" ";
                    }
                }
                cout<<"\n";
            }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}