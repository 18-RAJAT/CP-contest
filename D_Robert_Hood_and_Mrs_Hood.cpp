#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d,k;
    cin>>n>>d>>k;
    vector<int>StartOverlap(n+1,0),EndOverlap(n+1,0);
    for(int i=0;i<k;++i)
    {
        int l,r;
        cin>>l>>r;
        StartOverlap[r]++;
        EndOverlap[l-1]++;
    }
    partial_sum(StartOverlap.begin(),StartOverlap.end(),StartOverlap.begin());
    partial_sum(EndOverlap.rbegin(),EndOverlap.rend(),EndOverlap.rbegin());
    int MinJobOverlap=LLONG_MAX,MotherStartDay=0;
    int MaxJobOverlap=0,BrotherStartDay=0;
    for(int i=0;i+d<=n;++i)
    {
        int CurrentJobOverlap=k-StartOverlap[i]-EndOverlap[i+d];
        if(CurrentJobOverlap<MinJobOverlap)
        {
            MinJobOverlap=CurrentJobOverlap;
            MotherStartDay=i;
        }
        if(CurrentJobOverlap>MaxJobOverlap)
        {
            MaxJobOverlap=CurrentJobOverlap;
            BrotherStartDay=i;
        }
    }
    cout<<BrotherStartDay+1<<" "<<MotherStartDay+1<<endl;
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