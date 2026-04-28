class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size()>s.size())
            return "";

        unordered_map<char,int> tSet;
        unordered_map<char,int> sSet;

        int windowSize = t.size();

        for(auto& it : t)
            tSet[it]++;

        int count = 0;
        int countNeeded = tSet.size();

        int resultSize = INT_MAX;
        int start = -1;


        int i =0;
        bool freqSatisfied = false;

        for(int j = 0; j<s.size(); j++)
        {
            sSet[s[j]]++;

            if(tSet.count(s[j]) && sSet[s[j]]==tSet[s[j]])
                count++;

            while(count==countNeeded)
            {
                if(j-i+1<resultSize)
                {
                    resultSize = j-i+1;
                    start = i;
                }

                sSet[s[i]]--;

                if(tSet.count(s[i]) && sSet[s[i]]<tSet[s[i]])
                    count--;
                i++;
            }
        }

        return (start==-1) ? "" : s.substr(start,resultSize);
        
    }
};
