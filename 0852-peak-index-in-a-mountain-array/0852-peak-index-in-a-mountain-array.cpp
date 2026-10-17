class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int low=0;
       int high=arr.size()-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        //mid pe check kro .
        if(arr[mid+1]<arr[mid] && arr[mid-1]<arr[mid]){
            //yahi to peak hai.
            return mid;
        }
        else if (arr[mid+1]>arr[mid]){
            // we are at the increasing part..
            //humein aage jaane ki jarruat hai 
            low=mid+1;
        }
        else if(arr[mid+1]<arr[mid]){
            //we are in the decreasing part.
            high=mid-1;
        }
       } 
       return -1;
    }
};