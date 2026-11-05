class Solution {
public:
 long long f(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return i;
        }
    }
    return n;
 }
 bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
 }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1){
            return -1;
        }
        if(index !=0 && isprime(value) ){
            return -1;
        }
        int gap=n-1-index;
        if(value%2!=0){
            if(value - f(value) - (index-1)*2<=0){
                return -1;
            }
        }
        if( value - ( index)*2<=0)return -1;
        if(index==n-1){
            return value;
        }
        if(value%2==0){
            return value+ 1LL*gap*(2);
        }
        else{
            long long h=f(value);
            return value + h + 1LL*(gap-1)*2;
        }
        return 0;
    }
};