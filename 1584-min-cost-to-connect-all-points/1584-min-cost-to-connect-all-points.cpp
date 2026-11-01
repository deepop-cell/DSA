class Solution {
public:
    int find(int x, vector<int>&p){
        if(x==p[x]){
            return x;
        }
        return p[x]=find(p[x],p);
    }
    void Unite(int x, int y ,  vector<int>&parent,vector<int>&rank){
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>rank(n,1);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int wt=abs(x1-x2)+abs(y1-y2);
                edges.push_back({i,j,wt});
            }
        }
        //now i will put all the edge in min heap . wt,<a,b>.
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(auto &e:edges){
            int a=e[0];
            int b=e[1];
            int wt=e[2];
            pq.push({wt,{a,b}});
        }
        long long sum=0;
        while(!pq.empty()){
            auto curr=pq.top();
            int wt=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            int p1=find(x,parent);
            int p2=find(y,parent);
            if(p1==p2){
                continue;
            }
        sum+=wt;
        Unite(x,y,parent,rank);
        }
        return sum;

    }
};