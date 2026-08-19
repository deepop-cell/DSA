class Solution {
public:
int MOD=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int endw1=0;
        int endw0=0;
        bool has0=false;
        for(char &ch:binary){
            if(ch=='1'){
                endw1=(endw0+endw1+1)%MOD;
            }
            else{
                has0=true;
                endw0=(endw0+endw1)%MOD;
            }
        }
        return (has0)? (endw0+endw1+1)%MOD:(endw0+endw1)%MOD;
    }
};