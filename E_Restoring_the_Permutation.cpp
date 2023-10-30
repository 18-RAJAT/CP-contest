#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),check(n,false),b;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        check[a[i]-1]=true;
    }
    vector<int>minimum=a,maximum=a;
    for(int i=0;i<n;++i)
    {
        if(!check[i])
        {
            b.push_back(i+1);
        }
    }
    int j=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==a[i-1])
        {
            minimum[i]=b[j++];
        }
    }
    int idx=-1;
    for(int i=1;i<n;++i)
    {
        if(a[i]==a[i-1])
        {
            if(idx==-1)
            {
                idx=upper_bound(b.begin(),b.end(),a[i])-b.begin()-1;
                maximum[i]=b[idx--];
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<minimum[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<n;++i)
    {
        cout<<maximum[i]<<" ";
    }
    cout<<"\n";
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}