class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int left = 0;
        int right = heights.size()-1;

        int maxArea = 0;
        

        while(left<right)
        {
            int area = ((right-left)*(std::min(heights[left],heights[right])));
            maxArea = max(maxArea,area);

            if(heights[left]<=heights[right])
            {
                left++;
                continue;
            }
            if(heights[right]<=heights[left])
            {
                right--;
                continue;
            }
        }

        return maxArea;
    }
};
