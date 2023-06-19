class Solution {
public:
    // Recursive Solution: Gives TLE
    int solve(vector<vector<char>>& matrix, int row, int column, int& maxi)
    {
        // Base Case:
        if(row >= matrix.size() || column >= matrix[0].size()) return 0;

        // Call for right, left and diagonal index:
        int right = solve(matrix, row, column+1, maxi);
        int down = solve(matrix, row+1, column, maxi);
        int diagonal = solve(matrix, row+1, column+1, maxi);

        // Cheack for the present index:
        if(matrix[row][column] == '1')
        {
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans*ans);
            return ans;
        }

        else return 0;
    }

    // Memorisation:
    int solve2(vector<vector<char>>& matrix, int row, int column, int& maxi, vector<vector<int>>& dp)
    {
        // Base Case:
        if(row >= matrix.size() || column >= matrix[0].size()) return 0;

        // Checking for DP:
        if(dp[row][column] != -1) return dp[row][column];

        // Call for right, left and diagonal index:
        int right = solve2(matrix, row, column+1, maxi, dp);
        int down = solve2(matrix, row+1, column, maxi, dp);
        int diagonal = solve2(matrix, row+1, column+1, maxi, dp);

        // Cheack for the present index:
        if(matrix[row][column] == '1')
        {
            // Storing in dp:
            dp[row][column] = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, dp[row][column]*dp[row][column]);
            return dp[row][column];
        }

        else return 0;
    }

    // Tabulation:
    int solve3(vector<vector<char>>& matrix, int row, int column, int& maxi)
    {
        
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Recursive:
        // int maxSquare = 0;
        // int tempAns = solve(matrix, 0, 0, maxSquare);
        // return maxSquare;

        // Memorisation:
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        int maxSquare = 0;
        int tempAns = solve2(matrix, 0, 0, maxSquare, dp);
        return maxSquare;
    }
};