class Solution {
public:
    int solve(vector<int>& values, int i, int j)
    {
        // Base Case: When there are only two veretex
        if(i+1 == j) return 0;

        int ans = INT_MAX;
        for(int vertex=i+1; vertex<=j-1; vertex++)
        {
            ans = min(ans, values[i] * values[j] * values[vertex] + solve(values, i, vertex) + solve(values, vertex, j));
        }

        return ans;
    }

    int solve2(vector<int>& values, int i, int j, vector<vector<int>>& dp)
    {
        // Base Case: When there are only two veretex
        if(i+1 == j) return 0;

        // Checking for dp:
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int vertex=i+1; vertex<=j-1; vertex++)
        {
            ans = min(ans, values[i] * values[j] * values[vertex] + solve2(values, i, vertex, dp) + solve2(values, vertex, j, dp));
        }

        // Storing in dp:
        dp[i][j] = ans;

        return dp[i][j];
    }

    // Tabulation:
    int solve3(vector<int>& values)
    {
        // Creating dp vector and initializing it:
        vector<vector<int>> dp(values.size(), vector<int> (values.size(), 0));

        // Handling rest of the cases:
        for(int i=values.size()-1; i>=0; i--)
        {
            for(int j=i+2; j<values.size(); j++)
            {
                int ans = INT_MAX;
                for(int vertex=i+1; vertex<=j-1; vertex++)
                {
                    ans = min(ans, values[i] * values[j] * values[vertex] + dp[i][vertex] + dp[vertex][j]);
                }

                // Storing in dp:
                dp[i][j] = ans;
            }
        }

        return dp[0][dp.size()-1];
    }

    int minScoreTriangulation(vector<int>& values) {
        // return solve(values, 0, values.size()-1);

        // Memorisation:
        // vector<vector<int>> dp(values.size(), vector<int> (values.size(), -1));
        // return solve2(values, 0, values.size()-1, dp);

        // Tabulation:
        return solve3(values);
    }
};