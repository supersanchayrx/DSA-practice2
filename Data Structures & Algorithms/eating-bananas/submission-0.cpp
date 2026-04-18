class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxPileLen = 1;
        for(auto& it : piles)
            maxPileLen = std::max(it, maxPileLen);

        int left = 1;
        int right = maxPileLen;

        while(left<=right)
        {   
            int time = 0;
            int rate = (left+right)/2;

            for(int i = 0; i<piles.size(); i++)
            {
                time+=std::ceil((double)piles[i]/(double)rate);
            }

            if(time>h)
            {
                left = rate+1;
            }
            else
            {
                right = rate-1;
            }
        }

        return left;
    }
};
