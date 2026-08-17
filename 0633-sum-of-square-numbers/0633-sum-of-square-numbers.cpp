class Solution {
public:
    int f(int x){
        int i=1;
        int ans=0;
        while(1LL*i*i<=x){
            ans=i;
            i++;
        }
        return ans;
    }
    bool judgeSquareSum(int c) {
        int y=f(c);
        int l=0;
        int r=y;
        while(l<=r){
            long long sq=1LL*l*l + 1LL*r*r;
            if(sq==c){
                return true;
            }
            else if(sq<c){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};