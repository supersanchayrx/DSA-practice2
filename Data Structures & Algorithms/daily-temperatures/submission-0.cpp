class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans(temperatures.size(),0);
        stack<int> dayIndex;
        dayIndex.push(0);

        for(int i = 1; i<temperatures.size(); i++)
        {
            while(!dayIndex.empty() && temperatures[dayIndex.top()]<temperatures[i])
            {
                ans[dayIndex.top()] = i-dayIndex.top();
                dayIndex.pop();
            }

            dayIndex.push(i);
        }

        return ans;

    }
};
