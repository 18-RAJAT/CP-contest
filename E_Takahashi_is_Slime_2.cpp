#include<bits/stdc++.h>
using namespace std;
#define int long long

struct slime{int s,x,y;bool operator<(const slime&c)const{return s>c.s;}};
void sol()
{
    int h,w,x,p,q;
    cin>>h>>w>>x>>p>>q;
    p--,q--;
    vector<vector<int>>s(h,vector<int>(w));
    for(int i=0;i<h;++i)for(int j=0;j<w;++j)cin>>s[i][j];
    int c=s[p][q];
    vector<vector<int>>v(h,vector<int>(w));
    v[p][q]=2;
    vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
    priority_queue<slime>pq;
    for(auto& k:d)
    {
        int F=p+k.first,S=q+k.second;
        if(F>=0 && F<h && S>=0 && S<w && !v[F][S])
        {
            pq.push(slime{s[F][S],F,S});
            v[F][S]=1;
        }
    }
    while(!pq.empty())
    {
        int a=(c>=1?(c-1)/x:0);
        slime t=pq.top();
        if(t.s<=a)
        {
            pq.pop();
            c+=t.s;
            v[t.x][t.y]=2;
            for(auto& k:d)
            {
                int F=t.x+k.first,S=t.y+k.second;
                if(F>=0 && F<h && S>=0 && S<w && !v[F][S])
                {
                    pq.push(slime{s[F][S],F,S});
                    v[F][S]=1;
                }
            }
        }
        else break;
    }
    cout<<c;
}
signed main()
{
    sol();
    return 0;
}