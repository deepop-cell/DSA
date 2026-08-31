class MyCalendar {
public:
map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        int count=0;
        mp[startTime]++;
        mp[endTime]--;
        for(auto &it:mp){
            count+=it.second;
            if(count>1){
                mp[startTime]--;
                mp[endTime]++;//undoing before returning false/
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */