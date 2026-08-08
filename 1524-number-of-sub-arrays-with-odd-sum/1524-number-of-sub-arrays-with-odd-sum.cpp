class Solution {
    typedef long long ll;
public:
int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        ll oddsum=0;
        ll evensum=1;
        ll sum=0;
        ll count=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                evensum++;
                count+=oddsum;
            }
            else{
                oddsum++;
                count+=evensum;
            }
        }
        return count%MOD;
    }
};