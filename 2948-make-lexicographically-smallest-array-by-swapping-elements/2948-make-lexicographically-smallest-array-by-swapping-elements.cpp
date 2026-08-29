class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={nums[i],i};
        }
        sort(temp.begin(),temp.end());
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && temp[j].first-temp[j-1].first<=limit){
                j++;//expand the group/
            }
            vector<int>indices;
            for(int k=i;k<j;k++){
                indices.push_back(temp[k].second);
            }
            sort(indices.begin(),indices.end());
            for(int k=0;k<indices.size();k++){
                nums[indices[k]]=temp[i+k].first;
            }
            i=j;//next grp par jaao.
        }
     return nums;   
    }
};