#include<bits/stdc++.h>
using namespace std;
#define int long long
void generate(int pos,int n,int m,vector<int>&cur,vector<vector<int>>&seq)
{
    if(pos>n)
    {
        seq.push_back(cur);
        return;
    }
    int start=(pos==1)?1:cur[pos-2]+10;
    int ok=m-10*(n-pos);
    if(start>ok)return;
    for(int i=start;i<=ok;++i)
    {
        cur.push_back(i);
        generate(pos+1,n,m,cur,seq);
        cur.pop_back();
    }
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>cur;
    vector<vector<int>>seq;
    generate(1,n,m,cur,seq);
    cout<<seq.size()<<endl;
    for(auto& seq:seq)
    {
        for(int i=0;i<seq.size();++i)
        {
            if(i>0)cout<<" ";
            cout<<seq[i];
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}