#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol1()
{
    int n,m,k;
    cin>>n>>m>>k;
    int div=n/m,rem=n%m;
    ((n-(div+(rem!=0))<=k)?cout<<"NO"<<endl:cout<<"YES"<<endl);
}
void sol2()
{
    int n;
    cin>>n;
    map<int,int>mp;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    if(mp.size()==1)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=n,count=0;
    int init=a[0];
    for(int i=0;i<n;++i)
    {
        ((a[i]==init)?count++:(ans=min(ans,count),count=0));
    }
    cout<<min(ans,count)<<endl;
}
void sol3()
{
    string x,y;
    cin>>x>>y;
    int n=x.size();
    for(int i=0;i<n;++i)
    {
        if(x[i]==y[i])
        {
            continue;
        }
        //skip
        if(x[i]>y[i]){}
        else
        {
            swap(x[i],y[i]);
        }
        for(int j=i+1;j<n;++j)
        {
            //skip
            if(x[j]<y[j]){continue;}
            else
            {
                swap(x[j],y[j]);
            }
        }
        break;
    }
    cout<<x<<endl<<y<<endl;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // sol1();
        // sol2();
        sol3();
    }
    return 0;
}