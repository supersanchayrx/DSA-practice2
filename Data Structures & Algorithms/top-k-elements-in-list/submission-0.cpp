class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> ans;

        for(auto& it: nums)
        {
            mp[it]++;
        }


        for(auto& it : mp)
        {
            int val = it.first;
            int freq = it.second;

            buckets[freq].push_back(val);
        }

        for(int i =buckets.size()-1; i>=0; i--)
        {
            if(ans.size()==k)
                break;

            for(auto& it : buckets[i])
            {

                ans.push_back(it);

                if(ans.size()==k)
                    break;
            }
                
        }
        return ans;
    }
};
