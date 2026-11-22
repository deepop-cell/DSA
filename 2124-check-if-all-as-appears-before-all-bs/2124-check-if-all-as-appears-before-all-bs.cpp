class Solution {
public:
    bool checkString(string s) {
        if(s.length()==1){
            return true;
        }
       int x=-1;
       int y=-1;
       for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='a'){
            x=i;
        }
        if(y==-1){
            if(ch=='b'){
                y=i;
            }
        }
       } 
       if(y==-1)return true;
       return x<y;
    }
};