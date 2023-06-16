class Solution {
public:
    // // Method 1 solve function (Recursive): Gives TLE
    // int solve(vector<int>& cost, int i)
    // {
    //     if(i == 0) return cost[0];

    //     if(i == 1) return cost[1];

    //     int ans = min(solve(cost, i-1), solve(cost, i-2)) + cost[i];
    //     return ans;
    // }

    // // Method 2 solve function (Memorisation): Tc = O(n), SC = O(n)
    // int solve2(vector<int>& cost, vector<int>& dp, int i)
    // {
    //     // Base Cases:
    //     if(i == 0) return cost[0];

    //     if(i == 1) return cost[1];

    //     // If you already have value of min cost due to memorisation then dont go for recursion again:
    //     if(dp[i] != -1) return dp[i];

    //     // Recursive call and memorisation:
    //     dp[i] = min(solve2(cost, dp, i-1), solve2(cost, dp, i-2)) + cost[i];
    //     return dp[i];
    // }

    // // Method 3 solve function (Tabulation): Tc = O(n), SC = O(n)
    // int solve3(vector<int>& cost)
    // {
    //     int n = cost.size();
        
    //     // Creation of dp vector:
    //     vector<int> dp(n+1, -1);

    //     // Initialization of dp vector:
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];

    //     // Logic for dp Tabulation:
    //     for(int i=2; i<n; i++)
    //     {
    //         dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    //     }

    //     return min(dp[n-1], dp[n-2]);
    // }

    // Mehod 4 solve function (space optimisation): Tc = O(n), SC = O(1)
    int solve4(vector<int>& cost)
    {
        // Initializing curr, prev1, prev2:
        int curr;
        int prev1 = cost[1];
        int prev2 = cost[0];

        // Logic for dp space optimisation:
        for(int i=2; i<cost.size(); i++)
        {
            curr = min(prev1, prev2) + cost[i];
            prev2 = prev1; 
            prev1 = curr;
        }

        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // Method 1: Without DP
        // int n = cost.size();
        // return min(solve(cost, n-1), solve(cost, n-2));

        // Method 2: With DP(Memorisation)
        // int n = cost.size();
        // // create a DP vector:
        // vector<int> dp(n+1, -1);
        // int ans = min(solve2(cost, dp, n-1), solve2(cost, dp, n-2));
        // return ans;

        // Method 3: With DP(Tabulation)
        // int ans = solve3(cost);
        // return ans;

        // Method 4: With DP(Space Optimisation)
        return solve4(cost);

    }
};