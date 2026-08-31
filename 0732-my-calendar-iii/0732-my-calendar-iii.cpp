class MyCalendarThree {
public:
map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int maxintersection=0;
        int count=0;
        mp[startTime]++;
        mp[endTime]--;
        for(auto &it:mp){
            count+=it.second;
            maxintersection=max(maxintersection,count);
        }
        return maxintersection;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */