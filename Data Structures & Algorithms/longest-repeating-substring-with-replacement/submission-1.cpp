class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;

        int maxFreq = 0;

        int i = 0;
        int maxLen = 0;


        for(int j = 0; j<s.size(); j++)
        {
            char it = s[j];

            mp[it]++;

            maxFreq = std::max(maxFreq,mp[it]);

            //ok the idea is in a whindow, we want to make all of the char same
            //best way would be to replace characters that are less in freq 
            //so in a window, number of characters that are needed to be swapped for a diff char should be less that permittable operations 
            //i.e windowlen(j-i+1) - maxFreq = number of char that needed to be swapped
            //this should be less that k
            //if this is not the case, we shrink the window
            //the map just maintains whats currently inside the window
            while((j-i+1)-maxFreq>k)
            {
                //so if we move forward in the window by rejecting i elements from start
                mp[s[i]]--; //we update the map as well to remove those occurences of element at index i
                i++; // and ofc increment i as well
            }

            maxLen = std::max(maxLen,j-i+1);
        }

        return maxLen;
    }
};
