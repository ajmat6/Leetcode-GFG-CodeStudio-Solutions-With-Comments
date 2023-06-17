class Solution {
public:
    // Recursive: Gives TLE
    // int solve(int n)
    // {
    //     // Base Case:
    //     if(n == 0) return 0;

    //     int mini = INT_MAX;
    //     for(int i=1; i*i<=n; i++)
    //     {
    //         mini = min(mini, solve(n-i*i)+1);
    //     }

    //     return mini;
    // }

    // Memorisation:
    int solve2(int n, vector<int>& dp)
    {
        // Base Case:
        if(n == 0) return 0;

        // checking for value avialable in dp vector:
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++)
        {
            ans = min(ans, solve2(n-i*i, dp)+1);
        }

        dp[n] = ans;

        return dp[n];
    }

    // Tabulation:
    // int solve3(int n)
    // {
    //     // Creating dp vector and initializing it:
    //     vector<int> dp(n+1, 0);
    //     dp[0] = 0;

    //     for(int i=1; i<=n; i++)
    //     {
    //         dp[i] = INT_MAX;
    //         for(int j=1; j*j<=i; j++)
    //         {
    //             if(dp[i-j*j] >= 0)
    //                 dp[i] = min(dp[i], dp[i-j*j]+1);
    //         }
    //     }

    //     return dp[n];
    // }
    
    int numSquares(int n) {
        // return solve(n);

        // Memorisation:
        // vector<int> dp(n+1, -1);
        // return solve2(n, dp);

        // Tabulation:
        return solve3(n);
    }
};