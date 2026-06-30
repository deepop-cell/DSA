class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>result;
    int n=s.length();
    int k=p.length();
    if(k>n){
        return result;
    }  
    unordered_map<char,int>mp;
    for(char ch:p){
        mp[ch]++;
    }
    int count=mp.size();
    int l=0;
    for(int r=0;r<n;r++){
        if(mp.find(s[r])!=mp.end()){
            //matlab jo word include kr rhe hai wo mp mai paya gaya hai
            mp[s[r]]--;
            if(mp[s[r]]==0){
                count--;
            }
        }
        int currsize=r-l+1;
        if(currsize<k){
            continue;//abhi aur expand krna hai r ko
        }
        if(count==0){
            result.push_back(l);
        }
        
            //when currsize=k
            //shrink from left
            if(mp.find(s[l])!=mp.end()){
                //means jo left wala element tha wo tumhare map mai tha ab bahar ja rha hai
                if(mp[s[l]]==0){
                    //check kroge ki kya ye element ki wajah se anagram ban rha tha.
                    count++;//humara perfect match toot gaya kyuki left bahar ja rha hai. to count badha do
                }
                mp[s[l]]++;
            }
            l++;//slide left pointer.
        

    }
    return result;
    }
};