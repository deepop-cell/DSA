class Solution {
    //bhai ye to basic dsu ka question hai/......
    //== walo ko union krdo . first pass mai fir second pass mai != walo ka parents checkkaro .. agar barabar ho gya to return false. aur agar poora string iterate krlia to return true...
public:
vector<int>parent;
int find(int x){
    if(parent[x]==x){
        return x;
    }
    else {
        return parent[x]=find(parent[x]);//path compression..
    }
}
void Union(int x,int y,vector<int>&rank){
    int p1=find(x);
    int p2=find(y);
    if(p1!=p2){
        //parent alag alag hai tabhi union karoge 
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }
        else{
            //equal rank hai.
            parent[p1]=p2;//koi b parent banado aur rnak badha do uski.
            rank[p2]++;
        }
    }
}
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;//0 matlab a and so on 25 matlab z...
        }
        vector<int>rank(26,1);
        for(auto &x:equations){
            if(x[1]=='='){
                Union(x[0]-'a',x[3]-'a',rank);
            }
        }//pehle pass mai union krdo..
        //ab inequality dekho
        for(auto &x:equations){
            if(x[1]=='!'){
                if(find(x[3]-'a')==find(x[0]-'a')){
                    return false;
                }
            }
        }

    return true;
        
    }
};