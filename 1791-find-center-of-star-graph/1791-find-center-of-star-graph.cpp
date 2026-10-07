class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
       vector<int>deg(n+1,0);
       for(auto &edge:edges){
        int a=edge[0];
        int b=edge[1];
        deg[a]++;
        deg[b]++;
       } 

       for(int i=0;i<=n;i++){
        if(deg[i]==n-1){
            return i;
        }
       }
       return 0;
    }
};