class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool> map;

        for(auto it : nums)
        {
            if(!map[it])
                map[it]=true;
            else
                return true;
        }

        return false;
        
    }
};