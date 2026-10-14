class Solution {
public:
    int hammingWeight(int n) {
        long long cnt=0;
        while(n>0){
            if(n&1==1){
            //this checks for rightmost bit 
            cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
};