class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0];

        int maxProfit = 0;

        for(auto& it : prices)
        {
            if(buy>it)
            {
                buy = it;
                continue;
            }

            int profit = it - buy;
            maxProfit = std::max(profit,maxProfit);
        }

        return maxProfit;
    }
};
