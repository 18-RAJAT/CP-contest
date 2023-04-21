#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n,k;
    cin>>n>>k;
    vector<pair<long long int,long long int>>pairs;

    for(long long int i=0;i<n;i++)
    {
        cin>>pairs[i].first;
    }
    for(long long int i=0;i<n;i++)
    {
        cin>>pairs[i].second;
    }
    long long int ans=1e18;
    long long minimumNumberOfMoves=0;

    multiset<long long int>small,large;
    for(int i=0;i<n;++i)
    {
        long long int cells=pairs[i].second-pairs[i].first+1;

        if(small.size() and cells<=*small.rbegin())
        {
            small.insert(cells);
        }
        else
        {
            large.insert(cells);
            minimumNumberOfMoves+=cells;
        }
        while(small.size() and minimumNumberOfMoves<k)
        {
            minimumNumberOfMoves+=*small.rbegin();
            large.insert(*small.rbegin());
            small.erase(small.find(*small.rbegin()));
        }

        while(large.size() and minimumNumberOfMoves>=k)
        {
            if(minimumNumberOfMoves-*large.begin()<k)
            {
                break;
            }
            large.erase(large.find(*large.begin()));
            minimumNumberOfMoves-=*large.begin();
            small.insert(*large.begin());
        }
        if(minimumNumberOfMoves>=k)
        {
            // ans=min(ans,1LL*i+1);
            ans=min(ans,(long long)(2*large.size()+pairs[i].second-(minimumNumberOfMoves-k)));
        }
    }
    if(ans==1e18)
    {
        cout<<ans<<"\n";
    }
    else
    {
        cout<<"-1"<<"\n";
    }
}


int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}