class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        //brute froce approach is make a map and find the element whose frequency is 1.
        //but that would easily take o(n) extra space .
        int temp=0; 
        for(int bit=0;bit<=31;bit++){
            int zero=0;
            int one=0;
            for(int &x:nums){
                //check if ith bit is 0 or 1.
                if((x & 1<<bit)==0){
                    //bitth bit is 0 .
                    zero++;
                }
                else{
                    one++;
                }
                //ab check kro kon 3 ka multipke nhi hai .
            }
                if(one%3!=0){
                    //set the bith bit 1.
                    temp=(temp | (1<<bit));
                }
        }
        return temp;
    }
};