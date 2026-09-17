class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> answer;


        for(auto& it: nums)
            mp[it]++;

        for(auto& it: mp)
        {
            int val = it.first;
            int freq = it.second;

            buckets[freq].push_back(val);
        }

        for(int i = buckets.size()-1; i>=0; i--)
        {
            if(answer.size()==k)
                break;
            
            for(auto& it: buckets[i])
            {
                answer.push_back(it);
                if(answer.size()==k)
                    break;
            }
                
        }

        return answer;
    }
};
