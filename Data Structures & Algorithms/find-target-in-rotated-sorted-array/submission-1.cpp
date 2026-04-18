class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;

        while(left<=right)
        {
            int mid = (left+right)/2;

            if(nums[mid]==target)
            {
                return mid;
            }

            if(nums[left]<=nums[mid])
            {
                //the array is sorted on the left side
                if(nums[left]<=target && target<=nums[mid])
                {
                    //target lies in the left half itself
                    right = mid-1;
                }
                else
                {
                    //target lies in right half
                    left = mid+1;
                }
            }
            else
            {
                //right half is sorted 
                if(nums[mid]<=target && target<=nums[right])
                {
                    //target lies in right half itself
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }

        return -1;
    }
};
