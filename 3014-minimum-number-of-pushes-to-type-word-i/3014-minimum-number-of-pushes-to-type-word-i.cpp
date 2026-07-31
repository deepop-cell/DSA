class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int,int>mp;
        int assignkey=2;
        int result=0;
        for(char &ch:word){
            if(assignkey>9){
                assignkey=2;//for comign back again at 2 after 0/
            }
            mp[assignkey]++;//assigning char at the key
            result+=mp[assignkey];
            assignkey++;//moving ahead.
        }
        return result;
    }
};