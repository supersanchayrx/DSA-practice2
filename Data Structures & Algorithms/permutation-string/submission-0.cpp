class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;

        int i = 0;
        int windowSize = s1.size();
        
        vector<int> charSet1(26,0);
        vector<int> charSet2(26,0);
        

        for(int i = 0; i<windowSize; i++)
        {
            charSet1[s1[i]-'a']++;
            charSet2[s2[i]-'a']++;
        }

        if(charSet1==charSet2)
            return true;

        for(int i =windowSize; i<s2.size(); i++)
        {
            charSet2[s2[i]-'a']++;
            charSet2[s2[i-windowSize]-'a']--;

            if(charSet1==charSet2)
                return true;
        }

        return false;
    }
};
