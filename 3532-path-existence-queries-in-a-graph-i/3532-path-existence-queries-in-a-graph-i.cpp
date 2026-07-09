class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    else{
        return parent[x]=find(parent[x]);//path compression.
    }
}

void Union(int x,int y){
    int p1=find(x);
    int p2=find(y);
    if(p1!=p2){//parent alag honge tabhi union karenge na
       if(rank[p1]>rank[p2]){
        //jiska rank bada hau wo hee bnega parent.
        parent[p2]=p1;
       }
       else if(rank[p2]>rank[p1]){
        parent[p1]=p2;
       }
       else{
        //rank barabar hai to kisi ek ko hee parent lelo and rank++ lkardo uska.
        parent[p1]=p2;
        rank[p1]++;
       }
    }

    
}
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //sabse pehle adjacency list banalo.
        //since array is sorted, contunogous elements ke beech hee edge hoga
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=maxDiff){
                //matlab ye valid edge h.
                Union(i+1,i);
            }
        }
        vector<bool>res;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(parent[u]!=parent[v]){
                //matlab alag group hai to path nhi hoga/
                res.push_back(false);
            }
            else{
                res.push_back(true);
            }

        }
        return res;
    }
};