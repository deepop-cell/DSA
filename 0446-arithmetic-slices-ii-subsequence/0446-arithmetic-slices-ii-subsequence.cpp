class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<long long,int>mp[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-nums[j];
                auto it=mp[j].find(diff);
                int count_j=(it==mp[j].end())?0:it->second;
                //ab dekho since i<j.... to lentgh atleast 2 to hai, so ek include kroge to len 3 ho hee jayga kam se kam..so no check for len (hehe smart).
                mp[i][diff]+=count_j+1;//mp[i][diff] stores how many seuqence ending at i have difference diff, so we formed one more so we inc its count by one.(but pehle se jitne ban rhe the utne to bnenge hee plus ek aur aa jayga)
                result+=count_j;
            }
        }
        return result;
    }
};