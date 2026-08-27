class Solution {
public:
    bool check(long long x, int a,int b , int c,long long n){
        //we need to check if no of numbers div by a or b or c is greater than or equal to n..
        long long s1=x/a+x/b+x/c;
        long long lcm1=lcm((long long)a,(long long)b);
        long long lcm2=lcm((long long )b,(long long)c);
        long long lcm3=lcm((long long)a,(long long)c);
        long long lcm4=lcm((long long)lcm(a,b),(long long)c);
        long long  s2=x/lcm1 + x/lcm2+x/lcm3;
        long long  s3=x/lcm4;
        return s1-s2+s3>=n;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long  low=1;
        long long  high=2e18;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(check(mid,a,b,c,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};