class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {        
        int start_hours   = stoi(startTime.substr(0, 2));
        int start_minutes = stoi(startTime.substr(3, 2));
        int start_seconds = stoi(startTime.substr(6, 2));    
        int total_start_sec = (start_hours * 3600) + (start_minutes * 60) + start_seconds;
        int end_hours     = stoi(endTime.substr(0, 2));
        int end_minutes   = stoi(endTime.substr(3, 2));
        int end_seconds   = stoi(endTime.substr(6, 2));
        int total_end_sec = (end_hours * 3600) + (end_minutes * 60) + end_seconds;
        return abs(total_end_sec - total_start_sec);
    }
};