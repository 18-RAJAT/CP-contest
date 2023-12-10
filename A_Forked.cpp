#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b;
    cin>>a>>b;
    int xk,yk,xq,yq;
    cin>>xk>>yk>>xq>>yq;
    set<array<int,2>>pos1,pos2;
    //pos1 is the set of all possible positions of the knight
    pos1.insert({xk-a,yk-b});
    pos1.insert({xk-b,yk-a});

    //pos2 is the set of all possible positions of the queen
    pos1.insert({xk+a,yk+b});
    pos1.insert({xk+b,yk+a});

    //pos1 is the set of all possible positions of the knight
    pos1.insert({xk-a,yk+b});
    pos1.insert({xk-b,yk+a});

    //pos1 is the set of all possible positions of the knight
    pos1.insert({xk+a,yk-b});
    pos1.insert({xk+b,yk-a});

    //pos2 is the set of all possible positions of the queen
    pos2.insert({xq-a,yq-b});
    pos2.insert({xq-b,yq-a});

    //pos2 is the set of all possible positions of the queen
    pos2.insert({xq+a,yq+b});
    pos2.insert({xq+b,yq+a});

    //pos2 is the set of all possible positions of the queen
    pos2.insert({xq-a,yq+b});
    pos2.insert({xq-b,yq+a});

    //pos2 is the set of all possible positions of the queen
    pos2.insert({xq+a,yq-b});
    pos2.insert({xq+b,yq-a});
    int ans=0;
    for(auto& it:pos1)//for each position of the knight, check if it is a possible position of the queen
    {
        if(pos2.count(it))
        {
            ans++;
        }
    }
    cout<<ans<<endl;
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