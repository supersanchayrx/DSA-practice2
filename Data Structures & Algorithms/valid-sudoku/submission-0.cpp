class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for(int row = 0; row<9; row++)
        {
            if(!checkRows(board,row))
                return false;
        }
        for(int col = 0; col<9; col++)
        {
            if(!checkColumns(board,col))
                return false;
        }
        for(int row = 0; row<9; row+=3)
        {
            for(int col = 0; col<9; col+=3)
            {
                int squareIndex = (((row/3)*3) + (col/3));

                if(!checkSquare(board,squareIndex))
                    return false;
            }
        }

        return true;

    }

    bool checkRows(vector<vector<char>>& board, int row)
    {
        bool rowMap[9] = {false};
            for(int col = 0; col<9; col++)
            {
                if(isdigit(board[row][col]))
                    if(!rowMap[board[row][col]-'0'-1])
                        rowMap[board[row][col]-'0'-1] =true;
                    else
                        return false;
            }

        return true;
    }

    bool checkColumns(vector<vector<char>>& board, int col)
    {
        bool colMap[9] = {false};
            for(int row = 0; row<9; row++)
            {
                if(isdigit(board[row][col]))
                    if(!colMap[board[row][col]-'0'-1])
                        colMap[board[row][col]-'0'-1] =true;
                    else
                        return false;
            }

        return true;
    }

    bool checkSquare(vector<vector<char>> & board, int squareIndex)
    {
        bool squareMap[9] = {false};

        int rowStart = (squareIndex/3)*3;
        
        int colStart = squareIndex*3;
        if(colStart>=9 && colStart<18)
            colStart-=9;
        else if(colStart>=18)
            colStart-=18;

        for(int row = rowStart; row<rowStart+3; row++)
        {
            for(int col = colStart; col<colStart+3; col++)
            {
                if(isdigit(board[row][col]))
                    if(!squareMap[board[row][col]-'0'-1])
                        squareMap[board[row][col]-'0'-1] = true;
                    else
                        return false;
            }
        }

        return true;

        
    }
};
