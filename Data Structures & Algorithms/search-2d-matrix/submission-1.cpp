class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //finding potential row
        int start = 0;
        int end = matrix.size()-1;

        int rowIndex = -1;

        while(start<=end)
        {
            int potRow = (start+end)/2;
            int potRowStart = matrix[potRow][0];
            int potRowEnd = matrix[potRow][matrix[potRow].size()-1];

            if(potRowStart<=target && target<=potRowEnd)
            {
                rowIndex = potRow;
                break;
            }

            if(potRowStart>target)
            {
                end = potRow-1;
            }
            else if(potRowEnd<target)
            {
                start=potRow+1;
            }
        }

        if(rowIndex==-1)
            return false;

        int left = 0;
        int right = matrix[rowIndex].size()-1;

        while(left<=right)
        {
            int index = (left+right)/2;

            if(matrix[rowIndex][index]==target)
                return true;

            if(matrix[rowIndex][index]>target)
            {
                right = index-1;
            }
            else if(matrix[rowIndex][index]<target)
            {
                left = index+1;
            }
        }

        return false;
    }
};
