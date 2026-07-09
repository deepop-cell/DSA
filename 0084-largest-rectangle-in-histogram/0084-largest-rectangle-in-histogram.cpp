class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);

        }
        stack<int>st2;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st2.top();
            }
            st2.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
           int area=(nse[i]-pse[i]-1)*heights[i];
           maxarea=max(maxarea,area);
        }
        return maxarea;
        
    }
};