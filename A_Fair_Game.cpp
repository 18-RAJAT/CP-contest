#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[10001];
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int x;cin>>x;
        a[x]++;
    }
    for(int i=1;i<=100;++i)
    {
        for(int j=i+1;j<=100;++j)
        {
            if(a[i]+a[j]==n && a[i]==a[j])
            {
                cout<<"YES\n";
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
}