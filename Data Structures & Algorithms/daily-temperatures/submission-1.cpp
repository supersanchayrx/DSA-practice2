class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int,int>> dayIndex;
        vector<int> ans (temperatures.size(),0);

        dayIndex.push({0,temperatures[0]});

        for(int i = 1; i<temperatures.size(); i++)
        {
            while(!dayIndex.empty() && temperatures[i]>dayIndex.top().second)
            {
                int diff = i-dayIndex.top().first;
                ans[dayIndex.top().first] = diff;
                dayIndex.pop();
            }

            dayIndex.push({i,temperatures[i]});
        }

        return ans;
    }
};
