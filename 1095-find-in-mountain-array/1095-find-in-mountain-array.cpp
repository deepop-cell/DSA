/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      int n=mountainArr.length();
      int low=0;
      int high=n-1;
      int peak=-1;
      while(low<=high){
        int mid=low+(high-low)/2;
        int check=mountainArr.get(mid);
        int rcheck=(mid+1<n)?mountainArr.get(mid+1):INT_MAX;
        int lcheck=(mid>0)?mountainArr.get(mid-1):INT_MAX;
        if(check > rcheck && check > lcheck){
            peak=mid;
            break;
        }
        else if(rcheck>check){
            low=mid+1;
        }
        else if(lcheck>check){
            high=mid-1;
        }
      }  
      int idx=-1;
      int l=0;
      int h=peak;
      while(l<=h){
        int mid=l+(h-l)/2;
        int midval=mountainArr.get(mid);
        if(midval==target){
            return mid;
        }
        else if(midval>target){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
      }
      //*****THIS part only when not found in left partt.
      int left=peak+1;
      int right=n-1;
      while(left<=right){
        int mid=left+(right-left)/2;
        int midval=mountainArr.get(mid);
        if(midval==target){
            return mid;
        }
        else if(midval>target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
      }
      return -1;
    }
};