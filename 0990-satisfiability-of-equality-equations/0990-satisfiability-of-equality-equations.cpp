class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);//path compression
}
void Union(int x,int y,vector<int>&parent,vector<int>&rank){
    if(find(x)!=find(y)){
        int p1=find(x);
        int p2=find(y);
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            //equal ranks hai tooo,..
            parent[p1]=p2;
            rank[p2]++;
        }
    }
}
    bool equationsPossible(vector<string>& equations) {
        rank.resize(26,1);
        parent.resize(26);
        for(int i=0;i<25;i++){
            //a is 0 and z is 25.
            parent[i]=i;
        }
        for(auto &eq:equations){
            if(eq[1]=='='){
                int u=eq[0]-'a';
                int v=eq[3]-'a';
                Union(u,v,parent,rank);
            }
        }
        for(auto &eq:equations){
            if(eq[1]=='!'){
                int u=eq[0]-'a';
                int v=eq[3]-'a';
                if(find(u)==find(v)){
                    return false;
                }
            }
        }
        return true;
        
    }
};