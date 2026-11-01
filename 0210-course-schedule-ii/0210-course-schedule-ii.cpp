class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        //so first we need to check if cycle is there , 
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[b].push_back(a);
        }
        for(auto &e:edges){
            int a=e[0];
            int b=e[1];
            //b-->a
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};