class Solution {
public:
    bool isSafeToPlace(int row, int col, int n, vector<string> arr)
    {
        // check for the row:
        for(int i=col; i>=0; i--)
        {
            if(arr[row][i] == 'Q') return false;
        }

        // check for the column: No need to check as you are placing only one      queen in one column:

        // check for the diagonal:

        // for west-north diagonal
        int x = row;
        int y = col;
        while(x >=0 && y >=0)
        {
            if(arr[x][y] == 'Q') return false;

            x--;
            y--;
        }

        // for west-south diagonal
        x = row;
        y = col;
        while(x < n && y >=0)
        {
            if(arr[x][y] == 'Q') return false;

            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string> arr, string curr, int n)
    {
        // Base Case
        if(col == n)
        {
            ans.push_back(arr);
            return;
        }

        // Handle one case and rest for Recursion
        for(int row=0; row<n; row++)
        {
            if(isSafeToPlace(row, col, n, arr))
            {
                //if safe:
                arr[row][col] = 'Q';

                // Recursion handling:
                solve(col+1, ans, arr, curr, n);

                // Backtracking of the queens
                arr[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Initializing the ans vector:
        vector<vector<string>> ans;

        vector<string> arr;
        string curr;

        for(int i=0; i<n; i++) curr += '.';
        for(int i=0; i<n; i++) arr.push_back(curr);

        int col = 0;
        solve(col, ans, arr, curr, n);
        return ans;
    }
};