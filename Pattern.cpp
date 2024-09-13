#include <bits/stdc++.h>
using namespace std;
#define int long long

struct TreeNode
{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
    int countIslands(TreeNode*root)
    {
        return root?dfs(root,false):0;
    }
    
private:
    int dfs(TreeNode*node,bool parent)
    {
        if(!node) return 0;
        int islands=(node->val==1 && !parent)?1:0;
        islands+=dfs(node->left,node->val==1);
        islands+=dfs(node->right,node->val==1);
        return islands;
    }
};

signed main()
{
    TreeNode*root=new TreeNode(0);
    root->left=new TreeNode(1);
    root->right=new TreeNode(0);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(1);
    root->right->left=new TreeNode(1);
    root->right->right=new TreeNode(1);
    
    Solution sol;
    cout<<sol.countIslands(root)<<endl;
    return 0;
}