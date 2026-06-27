class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //adjacency list.
        unordered_map<int,vector<int>>adj;
        //indegree and outdegree map.
        //key----val yaani node----indegree/outdegree hai yaha par map mai.
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;
        for(auto &edge:pairs){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);//u-->v directed graph hai yaha par.
            outdegree[u]++;
            indegree[v]++;
        }
        //ab eulerian path ka start node find karna hai hume
        int n=indegree.size();
        int start=-1;
        for(auto it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                start=node;
                break;
            }
        }//maanlo eulerian circuit hua to start to -1 hee reh jayga kyuki tab sabka indeg - outdeg ==0 hoga
        //check
        if(start==-1){
            //put any random start because its eulerian cicruit;
            start=pairs[0][0];
        }
        //ab start se dfs krna hai.
        vector<int>eulerpath;//to store the path
        stack<int>st;//to perform dfs.
        st.push(start);
        while(!st.empty()){
            int node=st.top();
            if(!adj[node].empty()){//matlab edge baaki hai abhi bhi to visit.
            int nbr=adj[node].back();
            adj[node].pop_back();
            st.push(nbr);

            }
            else{
                //no neighbour left. matlab path mai push krdo ab
                eulerpath.push_back(node);
                st.pop();
            }
        }
        reverse(eulerpath.begin(),eulerpath.end());
        vector<vector<int>>result;
        //result banalo
        for(int i=0;i<eulerpath.size()-1;i++){
            result.push_back({eulerpath[i],eulerpath[i+1]});
        }
        return result;
    }
};