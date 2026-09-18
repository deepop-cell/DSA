class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        for(int i=0;i<s.length();i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a']=i;
            }
            end[s[i]-'a']=i;
        }
        //now we need to check valid start points.
        vector<bool>isValid(26,true);
        for(int c=0;c<26;c++){//checking starting points.
        if(start[c]==-1){
            continue;//this means we dont have this character in out string. so isko skip kardo na fir
        }
            for(int i=start[c];i<=end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    //this means this is a invalid start point.
                 isValid[c]=false;
                 break;
                }
                //also modify the endingfn point as well.
                end[c]=max(end[c],end[s[i]-'a']);//extending the end .
            }
        }
        vector<string>res;
        int lasttakenStart=INT_MAX;
        for(int i=s.length()-1;i>=0;i--){
            if(!isValid[s[i]-'a']) continue;
            //now check if we have encoutered a staritng point.
            if(i==start[s[i]-'a'] && end[s[i]-'a']<lasttakenStart){//to avoid overlap and we are iterating from right to left.
            lasttakenStart=i;
            res.push_back(s.substr(i,end[s[i]-'a']-i+1));
            }
        }
        return res;
    }
};