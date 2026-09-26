class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
       int op=0;
       queue<int>q;
       q.push(x);
       unordered_map<int,int>vis;
       vis[x]++;
       while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            int curr=q.front();
            q.pop();
            if(curr==y){
                return op;
            }
            if(curr%11==0 && !vis[curr/11]){
                int y=curr/11;
                q.push(y);
                vis[y]++;
            }
            if(curr%5==0 && !vis[curr/5]){
                int y=curr/5;
                q.push(y);
                vis[y]++;
            }
            if(curr>0 && !vis[curr-1]){
                q.push(curr-1);
                vis[curr-1]++;
            }
            if(curr<10011 && !vis[curr+1] ){
                q.push(curr+1);
                vis[curr+1]++;
            }
        }
        op++;
       }
       return -1; 
    }
};