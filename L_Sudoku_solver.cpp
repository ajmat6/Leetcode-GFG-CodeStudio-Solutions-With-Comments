// TC -> O(9^m) if there are m empty cell and each cell can have values to be put form 1 to 9 
// SC -> O(1) as there are only 81 iterations which is a constant value

class Solution {
public:
    bool isSafe(int row, int col, int value, vector<vector<char>> board)
    {
        for(int i=0; i<9; i++)
        {
            // Cheking for the row:
            if(board[row][i] == value) return false;

            // Checking for the column:
            if(board[i][col] == value) return false;
        }

        // Checking in the 3*3 matrix:
        int x = (row / 3) * 3;
        int y = (col / 3) * 3;
        int totalX = x + 3;
        int totalY = y + 3;

        for(int i=x; i<totalX; i++)
        {
            for(int j=y; j<totalY; j++)
            {
                if(board[i][j] == value) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int row=0; row<9; row++)
        {
            for(int col=0; col<9; col++)
            {
                // If empty cell is found:
                if(board[row][col] == '.')
                {
                    for(char value='1'; value<='9'; value++)
                    {
                        // Checking if it is safe to place:
                        if(isSafe(row, col, value, board))
                        {
                            // Insertion on the empty spot:
                            board[row][col] = value;

                            // Recusion call:
                            bool isSolutionFound = solve(board);

                            // If solution found return true:
                            if(isSolutionFound) return true;

                            // else do Backtracking:
                            else board[row][col] = '.';
                        }
                    }
                    return false; // No valid no is found to insert
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};