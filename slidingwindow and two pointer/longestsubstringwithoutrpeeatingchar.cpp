#include<iostream>
int max(int x, int y){
    return (x>y)? x:y;
}
int longestsubstringiwthrepeating(std::string s){
    int left=0;
    int right=0;
    int ans=0;
    std::string temp="";
    for(int right=0; right<s.size(); right++){

    while(temp.find(s[right]) != std::string::npos){
        temp.erase(0,1);
        left++;
    }

    temp += s[right];

    ans = max(ans, (int)temp.size());
}
    return ans;
}