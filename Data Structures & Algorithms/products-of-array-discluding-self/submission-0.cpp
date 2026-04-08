class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {   
        vector<int> prefixProd(nums.size());
        vector<int> suffixProd(nums.size());
        vector<int> ans(nums.size());
        

        for(int i =0; i<nums.size(); i++)
        {
            if(i==0)
            {
                prefixProd[i] = 1;
                continue;
            }

            prefixProd[i] = prefixProd[i-1]*nums[i-1];
        }

        for(int i =nums.size()-1; i>=0; i--)
        {
            if(i==nums.size()-1)
            {
                suffixProd[i] = 1;
                continue;
            }

            suffixProd[i] = suffixProd[i+1]*nums[i+1];
        }

        for(int i =0; i<nums.size(); i++)
        {
            ans[i] = prefixProd[i]*suffixProd[i];
        }

        return ans;
    }
};
