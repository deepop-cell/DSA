class Solution {
public:
int find(int x,vector<int>&parent){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x],parent);
}
void Unite(int x,int y,vector<int>&parent,vector<int>&rank){
    int p1=find(x,parent);
    int p2=find(y,parent);
    if(p1!=p2){
        if(rank[p1]>rank[p2]){
        parent[p2]=p1;
        }
        else if(rank[p1]<rank[p2]){
        parent[p1]=p2;
        }
        else{
        parent[p1]=p2;
        rank[p2]++;
        }
    }
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int comp=n;
               int count=0;
        vector<int>parentBoth(n+1);
        vector<int>rankBoth(n+1,1);
        for(int i=1;i<=n;i++){
            parentBoth[i]=i;
        }
        for(auto &x:edges){
            if(x[0]!=3){
                continue;
            }
            else{
                int a=x[1];
                int b=x[2];
                if(find(a,parentBoth)!=find(b,parentBoth)){
                    comp--;
                }
                else{
                    count++;
                }
                Unite(a,b,parentBoth,rankBoth);
            }
        }
        //first check if both and alice and bob can combine and make a connnected graph
        vector<int>rankalice(n+1,1);
        vector<int>rankbob(n+1,1);
        vector<int>parentalice=parentBoth;
        vector<int>parentbob=parentBoth;
        int comp1=comp;
        int comp2=comp;
        for(auto &x:edges){
            int a=x[1];
            int b=x[2];
            if(x[0]==1){
                if(find(a,parentalice)!=find(b,parentalice)){
                    comp1--;
                }
                else{
                    count++;
                }
                Unite(a,b,parentalice,rankalice);
            }
            if(x[0]==2){
                if(find(a,parentbob)!=find(b,parentbob)){
                    comp2--;
                }
                else{
                    count++;
                }
                Unite(a,b,parentbob,rankbob);
            }
        }
        if(comp1!=1 || comp2!=1){
            return -1;
        }
        //now traverse and check.
        return count; 
    }
};