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
        int pivot(MountainArray &mountainArr)
    {
        int s = 0;
        int e = mountainArr.length()-1;
        int mid = s + (e - s)/2;
        while(s<e)
        {
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                s = mid+1;
            else
                e = mid;
            mid = s + (e - s)/2;
        }
        return s;
    }

    int binarySearchForLeftMostElement(int s,int e,int target, MountainArray &mountainArr,string find)
    {
        int ans = -1;
        int mid = s + (e - s)/2;
        while(s<=e)
        {
            if(mountainArr.get(mid) == target)
            {
                ans = mid;
                e = mid-1;
            }
            
            else if(find == "left")
            {
                if(target > mountainArr.get(mid))
                    s = mid+1;
                else
                    e = mid-1;
            }
            else
            {
                if(target < mountainArr.get(mid))
                    s = mid+1;
                else
                    e = mid-1; 
            }
    
            mid = s + (e - s)/2;
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int ans = -1;

        int pivotIndex = pivot(mountainArr);

        if(mountainArr.get(pivotIndex)==target)
            return pivotIndex;

        ans = binarySearchForLeftMostElement(0,pivotIndex-1,target,mountainArr,"left"); 

        if(ans == -1) 
            ans = binarySearchForLeftMostElement(pivotIndex+1,mountainArr.length()-1,target,mountainArr,"right"); 

        return ans;
    }
};