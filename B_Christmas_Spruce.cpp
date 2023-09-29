#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>Tree;
/*
    Approach:
    We need to check if the given tree is a spruce tree or not.
    A spruce tree is a tree in which every non-leaf node has at least 3 leaf nodes.
    So, we need to check if every non-leaf node has at least 3 leaf nodes or not.
    We can do this by using dfs.
    If the current node is a leaf node, then we return true.
    If the current node is not a leaf node, then we need to check if it has at least 3 leaf nodes or not.
    If it has at least 3 leaf nodes, then we return true.
    If it does not have at least 3 leaf nodes, then we return false.
*/
bool dfs(int v,int parent=-1)
{
    bool leaf=Tree[v].empty();
    int cnt=0;
    for(auto& child:Tree[v])
    {
        if(!dfs(child,v))
        {
            return false;
        }
        if(!leaf)
        {
            if(Tree[child].empty())
            {
                cnt++;
            }
        }
    }
    return(leaf || cnt>=3);
}
void sol()
{
    int n;
    cin>>n;
    Tree.resize(n+1);
    for(int i=0;i<n-1;++i)
    {
        int p;
        cin>>p;
        p--;
        Tree[p].push_back(i+1);
    }
    cout<<(dfs(0)?"Yes":"No")<<"\n";
}
signed main()
{
  sol();
  return 0;
}