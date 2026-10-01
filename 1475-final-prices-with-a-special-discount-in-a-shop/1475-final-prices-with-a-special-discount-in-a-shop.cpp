class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
         while(!st.empty() && st.top()>prices[i]){
            st.pop();
         }
         if(st.empty()){
            nse[i]=0;
         }
         else{
            nse[i]=st.top();
         }
         st.push(prices[i]);
        }
        vector<int>ans(n);
        for(int i=0;i<prices.size();i++){
            ans[i]=prices[i]-nse[i];
        }
        return ans;
    }
};