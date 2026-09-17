class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(auto& s : strs)
        {
            int len = s.size();
            encoded_string+=to_string(len)+"#"+s;
        }

        return encoded_string;
    }

    // 5#hello5#world4#this2#is1#a4#test
    vector<string> decode(string s) {
        vector<string> answer;

        int currentIndex=0;

        while(currentIndex<s.size())
        {
            int length = lengthExtractor(s, currentIndex);
            string str = stringExtractor(s, currentIndex, length);
            answer.push_back(str);
        }

        return answer;
        
    }

    int lengthExtractor(string& str, int& currentIndex)
    {
        int calculatedLength = 0;
        for(int i = currentIndex; i<str.size(); i++)
        {
            char s = str[i];
            if(s>=48 && s<=57)
            {
                calculatedLength = calculatedLength*10 + (int)(s-'0');
                currentIndex++;
            }
            else
                break;
        }
        currentIndex++;

        return calculatedLength;
    }

    string stringExtractor(string& str, int& currentIndex, int length)
    {
        string decoded_string = "";
        for(int i = currentIndex; i<currentIndex+length; i++)
            decoded_string+=str[i];
        currentIndex+=length;
        return decoded_string;
    }
};
