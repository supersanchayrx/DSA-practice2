class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto word : strs)
        {
            vector<int> alphaCount(26,0);

            for(auto s : word)
            {
                alphaCount[s-'a']++;
            }

            string key = "";

            for(int i =0; i<26; i++)
            {
                key+=alphaCount[i]+'#';
            }

            mp[key].push_back(word);
        }

        for(auto it : mp)
            ans.push_back(it.second);


        return ans;

        
    }
};
