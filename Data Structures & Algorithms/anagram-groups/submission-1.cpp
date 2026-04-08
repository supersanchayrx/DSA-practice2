class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(auto str : strs)
        {
            int count[26] = {0};
            for(auto s : str)
            {
                count[s-'a']++;
            }

            string key = "";

            for(int i =0; i<26; i++)
            {
                key += count[i]+'#';
            }

            mp[key].push_back(str);
        }

        for(auto& it : mp)
        {
            ans.push_back(it.second);
        }


        return ans;
    
    }
};
