class Solution {
public:
    int maxProduct(int n) {
       priority_queue<int>pq;
        int temp=n;
        while(temp>0){
            int x=temp%10;
            pq.push(x);
            temp/=10;
        }
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        return a*b;        
    }
};