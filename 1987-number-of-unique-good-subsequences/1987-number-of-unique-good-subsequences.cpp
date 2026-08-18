class Solution {
public:
int MOD=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int ends_w_1=0;
        int end_w_0=0;
        bool has0=false;
        for(char &ch:binary){
            if(ch=='1'){
                ends_w_1=(ends_w_1+end_w_0+1)%MOD;
            }
            else{
                has0=true;
                end_w_0=(end_w_0+ends_w_1)%MOD;
            }
        }
        return (has0)?(ends_w_1+end_w_0+1)%MOD:(ends_w_1+end_w_0)%MOD;
    }
};