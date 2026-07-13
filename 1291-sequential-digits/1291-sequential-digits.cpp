class Solution {
public:
bool valid(int n,int low,int high){
    return (n>=low) && (n<=high);
}
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            if(valid(n,low,high)){
                res.push_back(n);
            }
            int ld=n%10;
            if(ld+1<=9){
                q.push(n*10 + (ld+1));///12--->123 mil jaygaaaa.
            }
        }
        return res;
    }
};