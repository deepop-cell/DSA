class Solution {
public:
        vector<int>rank;
        vector<int>parent;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);//path compression
    }
    void Union(int x,int y){
        int p1=find(x);
        int p2=find(y);
        if(p1==p2){
            return;
        }
        else{
            if(rank[p1]>rank[p2]){
                parent[p2]=p1;
            }
            else if(rank[p2]>rank[p1]){
                parent[p1]=p2;
            }
            else{
                //equal wala case
                parent[p2]=p1;
                rank[p1]++;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;//sab khudke hee parent hai initialyy
        }
        for(int i=0;i<n;i++){
            int r1=stones[i][0];
            int c1=stones[i][1];
            for(int j=0;j<n;j++){
                int r2=stones[j][0];
                int c2=stones[j][1];
                if(r1==r2 || c1==c2){
                    Union(i,j);//making groups.
                }

            }
        }
        //then finding number of difft groups.
        int group_count=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                group_count++;
            }
        }
        return n-group_count;        
    }
};