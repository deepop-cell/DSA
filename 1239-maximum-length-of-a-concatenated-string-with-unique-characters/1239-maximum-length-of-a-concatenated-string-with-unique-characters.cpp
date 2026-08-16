class Solution {
public:
    int solve(int i,vector<string>&arr,unordered_map<char,int>&mp){
        if(i>=arr.size()){
            return 0;
        }
        //check if arr[i] itself has duplicate chars or not
        unordered_map<char,int>f;
        bool internal_dup=false;
        for(int k=0;k<arr[i].length();k++){
            if(f.find(arr[i][k])!=f.end()){
                internal_dup=true;
                break;
            }
            f[arr[i][k]]++;
        }
        //now u ahve two choice , either include current in susbq or not.
        bool cantake=true;
        for(int j=0;j<arr[i].length();j++){
            if(mp.find(arr[i][j])!=mp.end()){
                //means this char ispresent .
                cantake=false;
                break;
            }
        }
        int take=0;
        if(cantake && !internal_dup){
            for(int j=0;j<arr[i].length();j++){
                mp[arr[i][j]]++;
            }
            take=arr[i].length()+solve(i+1,arr,mp);
            for(int j=0;j<arr[i].length();j++){
                mp.erase(arr[i][j]);//backtracking/
            }
        }
        int skip=solve(i+1,arr,mp);
        return max(skip,take);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int>mp;
        return solve(0,arr,mp);

    }
};