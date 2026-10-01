class Solution {
public:
pair<bool,bool> canmake(long long mid,long long n){
    if(mid*(mid+1)/2==n){
        ///means we can make 
        return {true,true};
    }
    else if(mid*(mid+1)/2>=(n) && (mid)*(mid-1)/2 <=n){
        return {true,false};
    }
    return {false,false};
}
    int arrangeCoins(int n) {
        long long low=1;
        long long high=n;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long total=mid*(mid+1)/2;
            if(total<n){
                low=mid+1;
            }
            else if(canmake(mid,n).first){
                if(canmake(mid,n).second){
                    return mid;
                }
                else if(canmake(mid,n).second==false){
                    return mid-1;
                }
            }
            else{
                high=mid-1;//try smaller.
            }
        }
        return 1;
    }
};