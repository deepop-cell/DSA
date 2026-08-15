class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=0;
        bool has_nonzero=false;
        for(int &x:nums){
            total^=x;
            if(x!=0){
                has_nonzero=true;
            }
        }
        //now if total xor is alrready non zero then its ans
        if(total!=0){
            return nums.size();
        }
        else if(total==0 && has_nonzero){
            return nums.size()-1;
        }
        else if(!has_nonzero){
            //all elements are 0/
            return 0;
        }
    return 0;
    }
};