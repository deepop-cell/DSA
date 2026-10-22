class Solution {
public:
bool check(vector<vector<int>>&a){
    vector<int>x;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            x.push_back(a[i][j]);
        }
    }

    for(int i=0;i<6;i++){
        if(x[i]!= i+1 && i!=5){
            return false;
        }
    }
    if(x[5]==0){
        return true;
    }
    return true;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>>q;
        q.push(board);
        set<vector<vector<int>>>st;
        st.insert(board);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                vector<vector<int>>curr=q.front();
                q.pop();
                if(check(curr)){
                    return level;
                }
                int x=-1;
                int y=-1;
                for(int i=0;i<2;i++){
                    for(int j=0;j<3;j++){
                        if(curr[i][j]==0){
                            x=i;
                            y=j;
                            break;
                        }
                    }
                }

                //now we can go in 4 directions 
                if(x+1<2){
                    vector<vector<int>>xx=curr;
                    swap(xx[x][y],xx[x+1][y]);
                    if(st.find(xx)==st.end()){
                        //matlab not vis hai 
                        q.push(xx);
                        st.insert(xx);
                    }
                }
                if(x>0){
                    vector<vector<int>>xx=curr;
                    swap(xx[x][y],xx[x-1][y]);
                    if(st.find(xx)==st.end()){
                        //matlab not vis hai 
                        q.push(xx);
                        st.insert(xx);
                    }
                }
                if(y+1<3){
                    vector<vector<int>>xx=curr;
                    swap(xx[x][y],xx[x][y+1]);
                    if(st.find(xx)==st.end()){
                        //matlab not vis hai 
                        q.push(xx);
                        st.insert(xx);
                    }
                }
                if(y>0){
                    vector<vector<int>>xx=curr;
                    swap(xx[x][y],xx[x][y-1]);
                    if(st.find(xx)==st.end()){
                        //matlab not vis hai 
                        q.push(xx);
                        st.insert(xx);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};