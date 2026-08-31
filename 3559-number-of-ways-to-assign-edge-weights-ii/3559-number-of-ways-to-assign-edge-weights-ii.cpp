#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int MOD = 1e9 + 7;
    int LOG;
    //this for filling the parents first column
    void dfs(int u, int p, int d, vector<int>& depth, vector<vector<int>>& up, const vector<vector<int>>& adj) {
        depth[u] = d;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            } else {
                up[u][i] = -1;
            }
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, depth, up, adj);
            }
        }
    }
//finding lca
    int get_lca(int u, int v, const vector<int>& depth, const vector<vector<int>>& up) {
        if (depth[u] < depth[v]) swap(u, v);
        // Lift u to the same depth as v
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        //Lift both until parents match
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        LOG = 20;

        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> up(n + 1, vector<int>(LOG, -1));
        vector<int> depth(n + 1, 0);
        dfs(1, -1, 0, depth, up, adj);
        vector<int> power2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            power2[i] = (power2[i - 1] * 2LL) % MOD;
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int lca_node = get_lca(u, v, depth, up);
            int k = depth[u] + depth[v] - 2 * depth[lca_node];
            ans.push_back(power2[k - 1]);
        }
        return ans;
    }
};