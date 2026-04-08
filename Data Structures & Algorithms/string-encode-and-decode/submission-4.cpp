class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encodedString = "";

        for(auto s : strs)
        {
            int length = s.size();
            encodedString += to_string(length)+"#"+s;
        }
        
        return encodedString;
    }

    vector<string> decode(string s) 
    {
        vector<string> ans;
        int length = 0;
        int indexTracker = 0;


        while(indexTracker<s.size())
        {
            int start = indexTracker;
            length = lengthExtractor(s,start,indexTracker);
            ans.push_back(extractString(s,indexTracker,indexTracker+length));
            indexTracker+=length;
        }

        return ans;
    }

    int lengthExtractor(string& str, int start, int& indexTracker)
    {
        int length = 0;
        for(int i = start; i<str.size();i++)
        {
            char s = str[i];

            if(s>=48 && s<=57)
            {
                length = (length*10) + (s-'0');
                indexTracker++;
                continue;
            }
            else
                break;
        }

        indexTracker++;
        return length;
    }

    string extractString(string& str, int start, int end)
    {
        string extractedString = "";
        for(int i =start; i<end; i++)
        {
            extractedString+=str[i];
        }

        return extractedString;
    }
};
