#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Query
{
    int x,y;
};
struct Pairs
{
    int m;
    multimap<int,int>mp;
    int pair_ct=0,maxi=0,ans=0;
    void process_query(int y)
    {
        auto range=mp.equal_range(y);
        int dist=distance(range.first,range.second);
        mp.insert({y,1});
        int choice1=dist,choice2=choice1+1;
        ans+=(choice2-1)*(choice2)>>1;
        ans-=(choice1-1)*(choice1)>>1;
        pair_ct++;
        if(maxi<choice2)
        {
            maxi=choice2;
        }
        int processed=ans,last=maxi-1;
        
        processed-=(last)*(last+1)>>1;
        last=maxi+(m-pair_ct)-1;
        processed+=(last)*(last+1)>>1;
        cout<<processed<<" ";
    }
};

void sol()
{
    int n;
    cin>>n;
    int m=n;
    Pairs Pairs;
    Pairs.m=m;
    for(int i=0;i<n;++i)
    {
        Query query;
        cin>>query.x>>query.y;
        // assert(query.x >= 0 && query.y >= 0);
        Pairs.process_query(query.y);
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
