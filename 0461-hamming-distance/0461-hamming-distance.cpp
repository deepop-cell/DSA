class Solution {
public:
    int hammingDistance(int x, int y) {
       int hdist=0;
       while(x>0 || y>0){
        int curr_x=x&1;
        int curr_y=y&1;
        if(curr_x!=curr_y){
            hdist++;
        }
        x>>=1;
        y>>=1;
       } 
       return hdist;
    }
};