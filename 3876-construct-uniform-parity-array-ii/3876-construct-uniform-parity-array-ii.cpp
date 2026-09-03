class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnodd=INT_MAX;
        for(int &x:nums1){
            if(x%2!=0){
                mnodd=min(mnodd,x);
            }
        }
        //now check if there is a even number for which its less than or equal to it.
        if(mnodd==INT_MAX){
            return true;
        }
        for(int &x:nums1){
            if(x%2==0){
                if(x<=mnodd){
                    return false;
                }
            }
        }
        return true;
    }
};