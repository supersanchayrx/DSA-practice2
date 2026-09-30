class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //row check
        for(int c=0; c<board.size(); c++)
            if(!RowCheck(board,c))
                return false;
        
        //col check
        for(int r=0; r<board[0].size(); r++)
            if(!ColCheck(board,r))
                return false;

        //square check
        for(int r=0; r<9; r+=3)
        {
            for(int c=0; c<9; c+=3)
            {
                if(!SquareCheck(board,r,c))
                    return false;
            }
        }

        return true;
    }

    bool RowCheck(vector<vector<char>>& board, int rowIndex)
    {
        bool rowMap[9]={false};

        for(int i = 0; i<9; i++)
            if(isDigit(board[rowIndex][i]))
                if(!rowMap[board[rowIndex][i]-'1'])
                    rowMap[board[rowIndex][i]-'1']=true;
                else
                    return false;
                
        return true;
    }

    bool ColCheck(vector<vector<char>>& board, int colIndex)
    {
        bool colMap[9]={false};

        for(int i = 0; i<9; i++)
            if(isDigit(board[i][colIndex]))
                if(!colMap[board[i][colIndex]-'1'])
                    colMap[board[i][colIndex]-'1']=true;
                else
                    return false;
                
        return true;
    }

    bool SquareCheck(vector<vector<char>>& board, int startRow, int startCol)
    {
        bool squareMap[9]={false};
        
        for(int row = startRow; row<startRow+3; row++)
        {
            for(int col = startCol; col<startCol+3; col++)
            {
                if(isDigit(board[row][col]))
                    if(!squareMap[board[row][col]-'1'])
                        squareMap[board[row][col]-'1']=true;
                    else
                        return false;
            }
        }
        
        return true;
    }

    bool isDigit(char c)
    {
        if(c>=49 && c<=57)
            return true;
        
        return false;
    }
};
