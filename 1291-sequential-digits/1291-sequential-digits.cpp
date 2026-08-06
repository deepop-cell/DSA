class Solution {
public:
bool isvalid(int n,int low,int high){
    return (n>=low && n<=high);
}
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(isvalid(curr,low,high)){
                ans.push_back(curr);
            }
            int ld=curr%10;
            if(ld<=8){
                q.push(curr*10+(ld+1));
            }
        }
        return ans;
    }
};