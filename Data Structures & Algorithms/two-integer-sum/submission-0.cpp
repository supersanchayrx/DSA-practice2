class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> soln;
        unordered_map<int,int> m;
        for(int i =0; i<nums.size(); i++)
        {
            soln.push_back(i);

            if(m.count(target-nums[i]))
            {
                soln.push_back(m[target-nums[i]]);
                if(soln[0]>soln[1])
                    std::swap(soln[0],soln[1]);
        
                return soln;
            }

            soln.clear();
            m[nums[i]]=i;
        }
    }
};
