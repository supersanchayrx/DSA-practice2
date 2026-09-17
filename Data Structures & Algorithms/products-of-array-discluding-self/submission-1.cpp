class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size(),1);
        vector<int> suffixProduct(nums.size(),1);

        for(int i = 0; i<nums.size(); i++)
        {   
            if(i==0)
                continue;

            prefixProduct[i]=nums[i-1]*prefixProduct[i-1];
        }

        for(int i = nums.size()-1; i>=0; i--)
        {   
            if(i==nums.size()-1)
                continue;

            suffixProduct[i]=nums[i+1]*suffixProduct[i+1];
        }

        for(int i=0; i<nums.size(); i++)
            suffixProduct[i]*=prefixProduct[i];

        return suffixProduct;
    }
};
