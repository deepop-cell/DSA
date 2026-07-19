class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int x_cnt=0;
        int y_cnt=0;
        for(auto &ch:s){
            if(ch==x){
                x_cnt++;
            }
            else if(ch==y){
                y_cnt++;
            }
        }
        string ans="";
        for(int i=0;i<y_cnt;i++){
            ans.push_back(y);
        }
        for(char &ch:s){
            if(ch!=x && ch!=y){
                ans.push_back(ch);
            }
        }
        for(int i=0;i<x_cnt;i++){
            ans.push_back(x);
        }
        return ans;
        
    }
};