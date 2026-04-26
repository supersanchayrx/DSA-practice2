class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        unordered_map<char,pair<int,bool>> mp;

        int i = 0;
        int j = 0;

        while(i<s.size() && j<s.size() && i<=j)
        {
            if(!mp[s[j]].second)
            {
                //this char is not yet encountered in this iteration
                pair<int,bool> pr = {j,true};
                mp[s[j]] = pr;
                j++;
            }
            else
            {
                maxLen = std::max(maxLen, j-i);
                i = std::max(i,mp[s[j]].first+1);
                mp[s[j]].second = false;
            }
        }

        maxLen = std::max(maxLen, j-i);
        return maxLen;

        
    }
};
