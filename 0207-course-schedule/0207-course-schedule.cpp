class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //we need to detect if ycle is there or not in graph.
        //use kahsn algo 
        queue<int>q;
        vector<int>ans;
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];
            //d graph bw v-->u
            adj[v].push_back(u);
        }
        for(int u=0;u<numCourses;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }
        for(int u=0;u<numCourses;u++){
            if(indegree[u]==0){
                q.push(u);//pushing all elements of indgereee 0 in the queue
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        //now see jin elements ka indegree 0 hai wo hee queue mai and ultimatelty ans mai jaynge to agaar cycle hoga to cycle waale elements ka indeg kabhi 0 hoga hee nhit o wo kabhi push hee nhi honge 
        if(ans.size()==numCourses)return true;
        return false;
    }
};