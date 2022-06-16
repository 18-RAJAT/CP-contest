/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<int>arr[],int v)
{
    vector<int> bfsStore;
    vector<int> vis(0,v+1);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsStore.push_back(node);
        for(auto it: arr[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }cout<<"hello";
    for(int i=0;i<bfsStore.size();i++)
        cout<<bfsStore[i]<<" ";
    cout<<endl;

}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> arr[v+1];
    for(int i=0;i<e;++i)
    {
        int u,t;
        cin>>u>>t;
        arr[u].push_back(t);
		arr[t].push_back(u);
    }
    bfs_traversal(arr,v);
    return 0;
}