class Solution {
public:
    // // Withour DP (Recursive) -> Gives TLE
    // int solve(vector<int>& coins, int amount)
    // {
    //     if(amount == 0) return 0;
    //     if(amount < 0) return INT_MAX;

    //     int mini = INT_MAX;
    //     for(int i=0; i<coins.size(); i++)
    //     {
    //         int ans = solve(coins, amount - coins[i]);

    //         if(ans != INT_MAX)
    //         {
    //             mini = min(mini, ans+1);
    //         }
    //     }

    //     return mini;
    // }

    // // With DP (Memorisation): TC = O(amount * no of coins), SC = O(amount)(recursive) + O(amount)(dp vector) -> Gives TLE
    // int solve2(vector<int>& coins, int amount, vector<int>& dp)
    // {
    //     // Base Case:
    //     if(amount == 0) return 0;
    //     if(amount < 0) return INT_MAX;

    //     // Checking if the required min coin value is already present in dp vector:
    //     if(dp[amount] != -1) return dp[amount];

    //     // Recursive calling:
    //     int mini = INT_MAX;
    //     for(int i=0; i<coins.size(); i++)
    //     {
    //         int ans = solve(coins, amount - coins[i]);

    //         if(ans != INT_MAX)
    //         {
    //             mini = min(mini, ans+1);
    //         }
    //     }

    //     // Storing the ans in dp vector for memorisation:
    //     dp[amount] = mini;

    //     return dp[amount];
    // }

    // With DP (Tabulation): TC = O(amount * no of coins), SC = O(amount)(dp vector)
    int solve3(vector<int>& coins, int amount)
    {
        // Create Tabulation dp vector:
        vector<int> dp(amount+1, INT_MAX);

        // Initialization:
        dp[0] = 0;

        // solve for each amount:
        for(int i=1; i<=amount; i++)
        {
            // now for each amount you have to look up for each type of coin:
            for(int j=0; j<coins.size(); j++)
            {
                // Tabulation logic:
                if(i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Mehtod 1: Without DP
        // int ans = solve(coins, amount);
        // if(ans == INT_MAX) return -1;
        // return ans;

        // Method 2: With DP
        // vector<int> dp(amount+1, -1);
        // int ans = solve2(coins, amount, dp);
        // if(ans == INT_MAX) return -1;
        // return ans;

        // Method 3: With DP(Tabulation)
        int ans = solve3(coins, amount);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};