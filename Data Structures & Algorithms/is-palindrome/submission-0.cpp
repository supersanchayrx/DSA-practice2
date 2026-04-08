class Solution {
public:
    bool isPalindrome(string s) 
    {
        vector<char> vec;

        for(auto& it : s)
        {
            if((it>=65 && it<=90) || (it>=97 && it<=122) || (it>=48 && it<=57))
            {
                if(it>=65 && it<=90)
                {
                    it=(char)(it+32);
                }

                vec.push_back(it);
            }  
        }

        
        int start = 0;
        int end = vec.size()-1;

        while(start<end)
        {
            if(vec[start]==vec[end])
            {
                start++;
                end--;
                continue;
            }
            
            return false;
        }

        return true;
    }
};
