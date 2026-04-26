class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        unordered_map<char,int> mp;

        int i = 0;

        for(int j = 0 ; j<s.size(); j++)
        {
            if(mp.count(s[j]) && mp[s[j]]>=i)
            {
                i = mp[s[j]]+1;
            }

            mp[s[j]]=j;
            maxLen = std::max(maxLen,j-i+1);
        }

        return maxLen;
    }
};
