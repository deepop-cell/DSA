class Solution {
public:
    double p(double x,long long n){
        n=abs(n);
        if(n==0){
            return 1;
        }
        double half=p(x,n/2);
        if(n%2==0){
            return  half*half;
        }
        else{
            return x * half * half;
        }
        return 0;
    }
    double myPow(double x, int n) {
        if(n<0){
            double f=p(x,n);
            return 1/f;
        }
        return p(x,n);
    }
};