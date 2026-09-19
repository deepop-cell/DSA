class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countneg=0;
        for(int &x:nums){
            if(x<0){
                countneg++;
            }
            else if(x==0){
                return 0;
            }
        }
        if(countneg%2==0){
            return 1;
        }
        else if(countneg%2!=0){
            return -1;
        }
        return 0;
    }
};