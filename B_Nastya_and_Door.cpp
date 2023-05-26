#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,k;
        cin>>n>>k;

        int x[n];
        memset(x,0,sizeof(x));

        int a[n];
        int cnt1=0;
        int cnt2=0;

        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<n-1;++i)
        {
            if(a[i-1]<a[i] and a[i+1]<a[i])
            {
                x[i+1]++;
            }
        }
        int b[n];
        memset(b,0,sizeof(b));

        b[0]=x[0];

        for(int i=1;i<n;++i)
        {
            b[i]=b[i-1]+x[i];
        }
        for(int i=k-1;i<n;++i)
        {
            if(cnt1<b[i]-b[i-k+2])
            {
                cnt1=b[i]-b[i-k+2];
                cnt2=i-k+1;
            }
        }
        cout<<cnt1+1<<" "<<cnt2+1<<"\n";
    }
}