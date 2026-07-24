class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int xr=nums[i]^nums[j];
                st.insert(xr);
            }
        }
        unordered_set<int>set;
        for(int i=0;i<n;i++){
               for(auto it:st){
                  int xor2=(it)^nums[i];
                  set.insert(xor2);
               }
        }
        return set.size();  
    }
};