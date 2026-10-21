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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,1);
        for(auto &p:pairs){
            int a=p[0];
            int b=p[1];
            Unite(a,b,parent,rank);
        }
        vector<vector<int>>group(n);
        for(int i=0;i<n;i++){
            group[find(i,parent)].push_back(i);
        }
        string s2=s;
        //ab jo jo indexes same comp mai hai unke elemnts ko sort krke ussi order mai place krte jao . 
        for(auto &g:group){
        string temp="";
        for(auto &i:g){
            temp.push_back(s[i]);
        }
        sort(temp.begin(),temp.end());
        int j=0;
        for(auto &i:g){
            s2[i]=temp[j];
            j++;
        }
        }

        return s2;
    }
};