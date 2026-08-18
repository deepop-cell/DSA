class Solution {
public:
int MOD=1e9+7;
    int distinctSubseqII(string s) {
        //nromal rec TLE dega kyuki 2 pwoer n legenege aur hum temp ki wjh se use memoise b nhi kr skte hai, to kya kre ab>?
        //1987 wala way, jab bhi koi char aa rha h to tumm  use sare 26 chars se end hone wale subs mai add kr kste +1 additional , ( wo char akela)..
        vector<int>end_w(26,0);
        for(char &ch:s){
            long long total=0;
            for(int &x:end_w){
                total=(total+x)%MOD;
            }
            end_w[ch-'a']=(total+1)%MOD;//total mai end_w[ch-'a] already hai to usme alag se add krne ki jrruat nai  hai.
        }
        long long ans=0;
        for(int &x:end_w){
            ans+=x;
        }
        return ans%MOD;
    }
};