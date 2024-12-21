#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node
{
    vector<int> Neg;
};
int Mex(vector<int>& s)
{
    vector<int>arr(5,0);
    for(auto& i:s)if(i>=0 && i<5)arr[i]=1;
    for(int i=0;i<5;++i)if(!arr[i])return i;
    return 5;
}
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<Node>graph(n+1);
    for(int i=1;i<=n;++i)
    {
        int l=(i-2+n)%n+1,r=(i)%n+1;
        graph[i].Neg.push_back(l);
        graph[i].Neg.push_back(r);
    }
    int adj=0;
    for(auto& i:graph[x].Neg)if(i==y)
    {
        adj=1;
        break;
    }
    if(!adj)
    {
        graph[x].Neg.push_back(y);
        graph[y].Neg.push_back(x);
    }
    int F=0;
    vector<int>Ans(n+1,-1);
    for(int i=0;i<=3 && !F;++i)
    {
        for(int j=0;j<=3 && !F;++j)
        {
            vector<int>a(n+1,-1);
            a[x]=i,a[y]=j;
            queue<int>q;
            q.push(x);
            if(x!=y)q.push(y);
            int gl=0;
            while(!q.empty() && !gl)
            {
                int u=q.front();
                q.pop();
                for(auto& v:graph[u].Neg)
                {
                    if(a[v]==-1)
                    {
                        vector<int>s;
                        for(auto& w:graph[v].Neg)if(~a[w])s.push_back(a[w]);
                        a[v]=Mex(s);
                        q.push(v);
                    }
                    else
                    {
                        vector<int>s;
                        for(auto& w:graph[v].Neg)if(~a[w])s.push_back(a[w]);
                        if(a[v]!=Mex(s))
                        {
                            gl=1;
                            break;
                        }
                    }
                }
            }
            if(!gl)
            {
                int ok=1;
                for(int i=1;i<=n;++i)if(a[i]==-1)
                {
                    ok=0;
                    break;
                }
                if(ok)
                {
                    Ans=a;
                    F=1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<Ans[i]<<(i<n?" ":"\n");
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