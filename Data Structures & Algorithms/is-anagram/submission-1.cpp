class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        vector<int> alphaCount(26,0);

        for(auto letter : s)
        {
            alphaCount[letter-'a']++;
        }

        for(auto letter : t)
        {
            alphaCount[letter-'a']--;
        }

        for(auto it : alphaCount)
            if(it!=0)
                return false;
        return true;
    }
};
