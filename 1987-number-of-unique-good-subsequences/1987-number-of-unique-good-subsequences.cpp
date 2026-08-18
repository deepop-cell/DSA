class Solution {
public:
int MOD=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int end0=0;
        int end1=0;
        bool has0=false;
        for(char &ch:binary){
            if(ch=='1'){
                end1=(end1 + end0 +1)%MOD;
            }
            else{
                has0=true;
                end0=(end1+end0)%MOD;
            }
        }
        return (has0)?(1+ end0+end1)%MOD:(end0+end1)%MOD;
    }
};