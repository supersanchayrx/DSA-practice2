class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> indexVal;
        int maxArea = 0;

        for(int i  = 0; i<heights.size(); i++)
        {
            while(!indexVal.empty() && heights[i]<indexVal.top().second)
                {
                    int nsi = i;
                    int ht = indexVal.top().second;
                    indexVal.pop();
                    int psi = indexVal.empty() ? -1 : indexVal.top().first;
                    int width = (nsi-psi-1);
                    int area = ht*width;
                    maxArea = std::max(area,maxArea);
                }

            indexVal.push({i,heights[i]});
        }

        while(!indexVal.empty())
            {
                int nsi = heights.size();
                int ht = indexVal.top().second;
                indexVal.pop();
                int psi = indexVal.empty() ?  -1 : indexVal.top().first;
                int width = (nsi-psi-1);

                int area = ht*width;
                maxArea = std::max(area,maxArea);
            }

        return maxArea;
    }
};
