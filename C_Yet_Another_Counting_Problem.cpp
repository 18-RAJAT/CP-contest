#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,q;
    cin>>a>>b>>q;
    if(a==b)
    {
        for(int i=0;i<q;++i)
        {
            int l,r;
            cin>>l>>r;
            cout<<0<<" ";
        }
        cout<<endl;
        return;
    }
    int Cycle=a*b,count=0;
    array<vector<int>,2>prefix;

    prefix[0].resize(Cycle);
    prefix[1].resize(Cycle);

    iota(prefix[0].begin(),prefix[0].end(),0);
    iota(prefix[1].begin(),prefix[1].end(),0);

    for(int i=0;i<Cycle;++i)
    {
        if((i%b)%a!=(i%a)%b)count++;
        prefix[0][i]=count;
        prefix[1][i]=i+1-count;
    }
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        int Cycle_R=r/Cycle,Rem_R=r%Cycle;
        int Cycle_L=(l-1)/Cycle,Rem_L=(l-1)%Cycle;

        int &ret=prefix[0][Cycle-1];
        int ans=Cycle_R*ret+prefix[0][Rem_R]-Cycle_L*ret-(Rem_L>=0?prefix[0][Rem_L]:0);

        cout<<ans<<" ";
    }
    cout<<endl;
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