#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>tables(n);
    for(int i=0;i<n;++i)
    {
        cin>>tables[i];
    }
    function<int(int,vector<string>&)>solve=[&](int n,vector<string>&tables)->int
    {
        int moves=0;
        vector<array<int,2>>counts(n,{0,0});
        for(int i=0;i<n;++i)
        {
            for(auto table:tables[i])
            {
                counts[i][table-'0']++;
            }
            int mismatch=min(counts[i][0],counts[i][1]);
            moves+=mismatch;
            counts[i][0]-=mismatch;
            counts[i][1]-=mismatch;
            if(counts[i][0])
            {
                if(i+1<n && counts[i+1][0])
                {
                    int mismatch=min(counts[i][0],counts[i+1][0]);
                    moves+=mismatch;
                    counts[i][0]-=mismatch;
                    counts[i+1][0]-=mismatch;
                }
            }
            else if(counts[i][1])
            {
                if(i+1>=n)
                {
                    return 0;
                }
            }
        }
        return moves;
    };
    cout<<solve(n,tables)<<endl;
}
signed main()
{
    sol();
    return 0;
}