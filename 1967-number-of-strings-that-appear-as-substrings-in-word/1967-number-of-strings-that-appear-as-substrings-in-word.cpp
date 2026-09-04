class Solution {
public:
    int numOfStrings(vector<string>& patterns, string s) {
        int count=0;
        for(int i=0;i<patterns.size();i++){
            if(s.find(patterns[i])!=string::npos){
                //mmeans exisits.
                count++;
            }
        }
        return count;
    }
};