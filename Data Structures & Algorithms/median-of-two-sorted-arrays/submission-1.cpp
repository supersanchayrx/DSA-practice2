class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        bool evenElements = ((nums1.size()+nums2.size())%2==0) ? true : false;

        int halfSizes = evenElements ? (nums1.size()+nums2.size())/2 : (nums1.size()+nums2.size()+1)/2; 

        int left = 0;
        int right = nums1.size();

        while(left<=right)
        {
            int mid = (left+right)/2; //these many elements would be picked from array 1
            int remaining = halfSizes-mid;

            int l1 = (mid-1>=0) ? nums1[mid-1] : INT_MIN;
            int l2 = (remaining-1>=0) ? nums2[remaining-1]: INT_MIN;

            int r1 = (mid<nums1.size()) ? nums1[mid] : INT_MAX;
            int r2 = (remaining<nums2.size()) ? nums2[remaining] : INT_MAX;

            if(l1<=r2 && l2<=r1)
            {
                if(evenElements)
                    return (std::max(l1,l2)+std::min(r1,r2))/2.0;
                
                return std::max(l1,l2);
            }
            else if(l1>r2)
            {
                right = mid-1;
                continue;
            }
            else if(l2>r1)
            {
                left = mid+1;
                continue;
            }  
        } 

        return 0;           
    }
};
