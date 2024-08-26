#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct node {
    int x, y, nxt;
};

array<node, 10 * N> p;
array<int, N> h, c, maxp, cmex0;
array<array<int, 2>, N> mex;
vector<vector<int>> g(N);

int Q, n, m, max1, x, s, cnt;
long long ans;

void in(int x, int y) {
    p[++cnt] = {x, y, h[x]};
    h[x] = cnt;
}

void dfs(int x) {
    if (maxp[x] != -1) return;
    maxp[x] = x;
    for (int k = h[x]; k != -1; k = p[k].nxt) {
        int y = p[k].y;
        dfs(y);
        maxp[x] = max(maxp[x], maxp[y]);
    }
}

long long sum(int x) {
    return 1ll * x * (x + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Q;
    while (Q--) {
        cin >> n >> m;
        max1 = 0;
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            int temp;
            cin >> temp;  // read the initial number (index, or size of subsequent inputs)
            max1 = max(max1, temp);
            for (int j = 0; j < temp; ++j) {
                cin >> x;
                g[i].push_back(x);
            }
        }

        cnt = 0;
        fill(h.begin(), h.begin() + max1 + 3, -1);
        s = 0;

        for (int i = 1; i <= n; ++i) {
            for (auto j : g[i]) c[min(j, N - 1)]++;
            mex[i][0] = 0;
            while (c[mex[i][0]]) mex[i][0]++;
            mex[i][1] = mex[i][0] + 1;
            while (c[mex[i][1]]) mex[i][1]++;
            for (auto j : g[i]) c[min(j, N - 1)]--;
            cmex0[mex[i][0]]++;
            s = max(s, mex[i][0]);
        }

        fill(maxp.begin(), maxp.begin() + max1 + 3, -1);
        for (int i = 0; i <= max1 + 2; ++i) dfs(i);

        if (cmex0[s] > 1) s = max(s, maxp[s]);

        ans = 0;
        for (int i = 0; i <= min(max1 + 2, m); ++i) {
            ans = max<int>(ans, maxp[i]);  // corrected logic for ans
        }

        if (m <= max1 + 2) {
            cout << ans << "\n";
        } else {
            cout << ans + sum(m) - sum(max1 + 2) << "\n";
        }

        for (int i = 1; i <= n; ++i) {
            cmex0[mex[i][0]]--;
        }
    }

    return 0;
}
