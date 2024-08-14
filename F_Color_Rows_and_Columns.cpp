#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M1=1005,M2=105;
int dp[M2][M2][M2];
int row_col_color_change;

//use this template from external source
struct SegmentTree{
    vector<vector<int>> tree;
    int size;

    SegmentTree(int n, int k) {
        size = n + 5;
        tree.resize(4 * size, vector<int>(k + 5, 1e9));
    }

    void build(int node, int start, int end, int k) {
        if (start == end) {
            fill(tree[node].begin(), tree[node].end(), row_col_color_change);
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, k);
            build(2 * node + 1, mid + 1, end, k);
            for (int i = 0; i <= k; ++i) {
                tree[node][i] = min(tree[2 * node][i], tree[2 * node + 1][i]);
            }
        }
    }

    void update(int node, int start, int end, int idx, const vector<int>& row_col_color_change, int k) {
        if (start == end) {
            tree[node] = row_col_color_change;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, row_col_color_change, k);
            } else {
                update(2 * node + 1, mid + 1, end, idx, row_col_color_change, k);
            }
            for (int i = 0; i <= k; ++i) {
                tree[node][i] = min(tree[2 * node][i], tree[2 * node + 1][i]);
            }
        }
    }

    vector<int> query(int node, int start, int end, int l, int r, int k) {
        if (r < start || end < l) {
            return vector<int>(k + 5, 1e9);
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        vector<int> p1 = query(2 * node, start, mid, l, r, k);
        vector<int> p2 = query(2 * node + 1, mid + 1, end, l, r, k);
        vector<int> result(k + 5, 1e9);
        for (int i = 0; i <= k; ++i) {
            result[i] = min(p1[i], p2[i]);
        }
        return result;
    }
};

void recurrence(SegmentTree& segTree, int n, int k) {
    vector<vector<int>> dp2(n + 5, vector<int>(k + 5, row_col_color_change));
    dp2[0][0] = 0;
    segTree.update(1, 0, n + 4, 0, dp2[0], k);

    for (int t = 1; t <= n; ++t) {
        int x, y;
        cin >> x >> y;
        vector<int> ndp(k + 5, row_col_color_change);
        for (int e = 0; e <= k + 1; ++e) {
            vector<int> result = segTree.query(1, 0, n + 4, 0, t - 1, k);
            for (int c = 0; c <= e; ++c) {
                ndp[e] = min(ndp[e], result[e - c] + dp[x][y][c]);
            }
        }
        segTree.update(1, 0, n + 4, t, ndp, k);
    }

    vector<int> result = segTree.query(1, 0, n + 4, n, n, k);
    int ans = min(result[k], result[k + 1]);
    cout << (ans == row_col_color_change ? -1 : ans) << "\n";
}
void precompute()
{
    for(int i=0;i<M2;++i)
    {
        for(int j=0;j<M2;++j)
        {
            for(int k=0;k<M2;++k)
            {
                dp[i][j][k]=(k==0?0:1e9);
            }
        }
    }

    for(int i=1;i<M2;++i)
    {
        for(int j=1;j<M2;++j)
        {
            for(int k=0;k<M2;++k)
            {
                int cols1,cols2;
                if(j==1)cols1=i+1;
                else cols1=1;
                
                if(i==1)cols2=j+1;
                else cols2=1;
                int &ret=dp[i][j][k];
                if(cols1<=k)
                {
                    ret=min(ret,dp[i][j-1][k-cols1]+i);
                }
                if(cols2<=k)
                {
                    ret=min(ret,dp[i-1][j][k-cols2]+j);
                }
            }
        }
    }
}
signed main()
{
    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        SegmentTree segTree(n,k);
        vector<int>temp(1);
        temp[0]=dp[70][70][70];
        fill(temp.begin(),temp.end(),temp[0]);
        row_col_color_change=temp[0];
        row_col_color_change=dp[70][70][70];
        segTree.build(1,0,n+5,k);
        recurrence(segTree,n,k);
    }
}
