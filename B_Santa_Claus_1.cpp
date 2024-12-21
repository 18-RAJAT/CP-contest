#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int h,w,x,y;
    cin>>h>>w>>x>>y;
    vector<string>vs(h);
    for(int i=0;i<h;++i)cin>>vs[i];
    string t;
    cin>>t;
    set<pair<int,int>>st;
    for(auto& c:t)
    {
        if(vs[x-1][y-1]=='@')st.insert({x-1,y-1});
        if(c=='U' && vs[x-2][y-1]!='#')x--;
        else if(c=='D' && vs[x][y-1]!='#')x++;
        else if(c=='L' && vs[x-1][y-2]!='#')y--;
        else if(c=='R' && vs[x-1][y]!='#')y++;
        if(vs[x-1][y-1]=='@')st.insert({x-1,y-1});
    }
    cout<<x<<" "<<y<<" "<<st.size()<<endl;
}
signed main()
{
    int t=1;
    while(t--)
    {
        sol();
    }
    return 0;
}