#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    while(t-->0)
    {
        long long int n;
        cin>>n;
        long long int a[100005];
        memset(a,0,sizeof(a));

        for(long long int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        if(a[n]==1)
        {
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES"<<"\n";
        vector<long long int>seq;
        for(long long int i=1;i<=n;++i)
        {
            if(a[i]!=a[i+1])
            {
                seq.push_back(i);
            }
        }
        for(long long int i=0;i<n-seq.size();++i)
        {
            cout<<0<<" ";
        }
        for(long long int i=0;i<seq.size();++i)
        {
            cout<<seq[i]<<" ";
        }
        cout<<"\n";
    }
}