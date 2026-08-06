class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(1){
            int temp=n;
            int r_p=1;
            while(temp>0){
                r_p*=(temp%10);
                temp/=10;
            }
            if( r_p % t==0){
                break;
            }
            else{
                n++;
            }
        }
        return n;
    }
};