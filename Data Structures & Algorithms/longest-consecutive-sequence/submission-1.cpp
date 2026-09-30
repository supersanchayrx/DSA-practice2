class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> possibleStartPoints;
        int maxLength = 1;

        for(auto& it : nums)
        {
            mp[it]++;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(mp.count(nums[i]-1))
                continue;
            else
                possibleStartPoints.push_back(nums[i]);
        }

        for(auto& it : possibleStartPoints)
        {
            int currLength = 1;

            while(mp.count(it++))
                currLength++;

            maxLength = std::max(currLength, maxLength);
        }

        return maxLength-1;
    }
};
