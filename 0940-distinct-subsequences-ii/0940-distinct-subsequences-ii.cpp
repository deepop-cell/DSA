class Solution {
public:
int MOD=1e9+7;
    int distinctSubseqII(string s) {
        vector<int>end_w(26,0);
        for(char &ch:s){
            long long total=0;
            for(int &x:end_w){
                total+=x;
            }
            end_w[ch-'a']=(total+1)%MOD;
        }
        long long ans=0;
        for(int &x:end_w){
            ans+=x;
        }
        return ans%MOD;
        
    }
};