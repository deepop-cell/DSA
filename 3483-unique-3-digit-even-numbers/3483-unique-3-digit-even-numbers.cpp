class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       unordered_set<int>st;
       for(int i=0;i<digits.size();i++){
        for(int j=0;j<digits.size();j++){
            for(int k=0;k<digits.size();k++){
                if(i==j || j==k || i==k){
                    continue;
                }
                int nums=100*digits[i]+10*digits[j]+digits[k];
                if(nums>=100 && nums%2==0){
                st.insert(nums);
                }
            }
        }
       } 
       return st.size();
    }
};