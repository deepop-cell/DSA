class Solution {
public:
typedef long long ll;
    ll getsum(string &ans){
        ll sum=0;
         for(int i=0;i<ans.length();i++){
            sum+=ans[i]-'0';
         }
        return sum;
    }
    string maxSumOfSquares(int num, int sum) {
      string ans="";
        int taken=0;
        ll ogsum=sum;
        while(sum>=0 && taken<num){
            for(int i=9;i>=0;i--){
                if(sum<i){
                    continue;
                }
                else{
                    sum-=i;
                    taken++;
                    ans.push_back('0'+i);
                    break;
                }
            }
        }
        if(taken==0){
            return "";
        }
        //check sum of digits.
        ll s=getsum(ans);
        if(s!=ogsum){
            return "";
        }
        return ans;
    }
};