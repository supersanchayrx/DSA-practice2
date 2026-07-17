class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::sort(nums.begin(),nums.end());
        vector<vector<int>> answers;

        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;

            int val = nums[i];
            int high = nums.size()-1;
            int low = i+1;

            while(low<high)
            {
                if(nums[low]+nums[high]==-val)
                {
                    answers.push_back({nums[low],nums[high],val});

                    while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>-val)
                {
                    high--;
                    continue;
                }
                else if(nums[low]+nums[high]<-val)
                {
                    low++;
                    continue;
                }
            }
        }

        return answers;
    }
};
