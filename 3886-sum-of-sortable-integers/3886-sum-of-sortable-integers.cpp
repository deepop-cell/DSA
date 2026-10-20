class Solution {
public:
    bool IS(vector<int>&nums){
      int dips=0;
      int n=nums.size();
      for(int i=0;i<nums.size();i++){
        if(nums[(i+1)%n]<nums[i]){
            dips++;
        }
      }
      return dips<=1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
      vector<int>divisors;
      divisors.push_back(1);
      for(int i=2;i*i<=n;i++){
        if(n%i==0){
            divisors.push_back(i);
            if(n/i !=i){
                divisors.push_back(n/i);//other divisor.
            }
        }
      }  
      //now try all divisors.
      int ans=0;
      bool sorted=true;
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]<nums[i]){
            sorted=false;
            break;
        }
      }
      if(sorted){
        ans+=(n);
      }
      else{
        bool check=IS(nums);
        //check if rotated and sorted .
        if(check){
            ans+=n;
        }
      }
      for(int i=0;i<divisors.size();i++){
        bool f=true;
        int k=divisors[i];
        //ab k k ke groups bannao.
            //now check after sorted each group is our array sorted
            vector<int>temp(nums.begin(),nums.end());
            int j=0;
            while(j<n){
                vector<int>x(temp.begin()+j,temp.begin()+j+k);
                if(!IS(x)){
                    f=false;
                    break;
                }
                sort(temp.begin()+j,temp.begin()+j+k);
                j+=k;
            }
            if(!f){
                continue;
            }
            //now check if whole arr becomes sorted 
           bool s=true;
           for(int a=0;a<temp.size()-1;a++){
            if(temp[a+1]<temp[a]){
                s=false;
                break;
            }
           }
           if(s){
            ans+=k;
           }    
      }
      return ans;
    }
};