class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_map<int,int>mp;

        for(auto& it : nums)
        {
            mp[it]++;
        }

        vector<int> possibleStartPoints;

        for(auto& it : mp)
        {
            int letStart = it.first;
                if(mp.count(letStart-1))
                    continue;
            
            possibleStartPoints.push_back(letStart);
        }

        int maxConsecutive = 0;
        int currentConsecutive = 0;

        for(auto& it : possibleStartPoints)
        {
            int start = it;
            while(mp.count(it++))
            {
                currentConsecutive++;
                maxConsecutive = max(currentConsecutive, maxConsecutive);
            }
            currentConsecutive= 0;
        }

        return maxConsecutive;

    }
};
