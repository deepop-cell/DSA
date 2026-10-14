class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips=0;
        while(start>0 || goal>0 ){
            int a_r=start&1;
            int b_r=goal&1;
            if(a_r!=b_r){
                flips++;
            }
            start>>=1;
            goal>>=1;
        }
        return flips;
    }
};