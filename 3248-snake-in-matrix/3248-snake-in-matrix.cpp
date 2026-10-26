class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
      int i=0;
      int j=0;
      for(auto &x:commands) {
        if(x[0]=='U'){
            i--;
        }
        else if(x[0]=='R'){
            j++;
        }
        else if(x[0]=='L'){
            j--;
        }
        else{
            i++;
        }
      }
      return n*i + j;
    }
};