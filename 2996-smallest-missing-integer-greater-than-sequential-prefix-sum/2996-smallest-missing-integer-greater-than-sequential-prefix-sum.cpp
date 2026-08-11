class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int bestsum=0;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1){
                sum+=(nums[i]);
            }
            else{
                break;
            }
        }
        bestsum=max(bestsum,sum);
        set<int>st;
        for(int &x:nums){
            if(x>=bestsum){
                st.insert(x);
            }
        }
        int counter=bestsum;
        while(1){
            if(st.find(counter)!=st.end()){
                //matlab mil gaya . move ahead
                counter++;
            }
            else{
                //nahi mila
                break;
            }
        }
        return counter;
    }
};