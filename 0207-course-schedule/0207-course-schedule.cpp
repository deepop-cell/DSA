class Solution {
public:
    bool iscycle(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
        vis[node]=true;
        pathvis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                if(iscycle(v,adj,vis,pathvis)){
                    return true;
                }
            }
            else if(vis[v] && pathvis[v]){
                return true;
            }
        }
        pathvis[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ///for [ai,bi] we have edge bi--->ai. so so see we have to check if there is a cycle or not in the directed graph, its just that path vis and vis method ,

        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto &i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,adj,vis,pathvis)){
                    //agar cycle hai to courses complete nhi kar paenge kyuki fas jaynge .
                    return false;
                }
            }
        }
        //if no cycel then u can complete all the courses.
        return true;
    }
};