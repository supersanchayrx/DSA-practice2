class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        bool bMap[1000] = {false};

        for(int i=0; i<strs.size(); i++)
        {
            if(bMap[i])
                continue;
            
            bMap[i]=true;
            string curr = strs[i];
            vector<string> ans2;
            ans2.push_back(curr);

            for(int j=i+1; j<strs.size(); j++)
            {
                if(curr.size()!=strs[j].size() || bMap[j])
                    continue;

                string curr2 = strs[j];
                int arr[26] = {0};

                for(int k=0; k<curr2.size(); k++)
                {
                    arr[curr[k]-'a']++;
                    arr[curr2[k]-'a']--;
                }

                int counter = 0;
                for(auto it : arr)
                    if(it>0)
                        break;
                    else counter++;

                if(counter==26)
                {
                    ans2.push_back(curr2);
                    bMap[j]=true;
                } 
            }

            ans.push_back(ans2);
        }

        return ans;
    
    }
};
