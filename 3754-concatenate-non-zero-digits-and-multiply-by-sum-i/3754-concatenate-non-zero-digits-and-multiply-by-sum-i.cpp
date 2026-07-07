class Solution {
public:
    long long sumAndMultiply(int n) {
        stack<int>st;
        int temp=n;
        long long sum=0;
        while(temp>0){
            if(temp%10!=0){
            st.push(temp%10);
            sum+=st.top();
            }
            temp/=10;
        }
        long long f=0;
        int div=st.size()-1;
        while(!st.empty()){
            f+=st.top()*(pow(10,div));
            div--;
            st.pop();
        }
        long long ans=1ll*f*sum;
        return ans;
    }
};