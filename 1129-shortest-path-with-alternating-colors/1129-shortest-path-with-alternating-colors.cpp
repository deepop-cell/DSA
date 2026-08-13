#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // {neighbor, color}
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < redEdges.size(); i++) {
            int u = redEdges[i][0];
            int v = redEdges[i][1];
            adj[u].push_back({v, 0}); // 0 = Red
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];
            adj[u].push_back({v, 1}); // 1 = Blue
        }
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        queue<pair<int, int>> q;
        q.push({0, -1});
        vector<int> distance(n, INT_MAX);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int currnode = q.front().first;
                int currcolour = q.front().second;
                q.pop();
                distance[currnode]=min(distance[currnode],level);
                for (auto &temp : adj[currnode]) {
                    int adjnode = temp.first; 
                    int edgecolour = temp.second; 
                    if (edgecolour != currcolour && !vis[adjnode][edgecolour]) {
                        vis[adjnode][edgecolour] = true; // Mark as visited with this edge color
                        q.push({adjnode, edgecolour});
                    }
                }
            }
            level++;
        }
        for(int i=0;i<distance.size();i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        return distance;
    }
};