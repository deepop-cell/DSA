class Solution {
public:
    bool checkDivisibility(int n) {
        int digprod=1;
        int digsum=0;
        int temp=n;
        while(temp>0){
            digprod*=(temp%10);
            digsum+=(temp%10);
            temp/=10;
        }
    return n%(digprod+digsum)==0;
    }
};