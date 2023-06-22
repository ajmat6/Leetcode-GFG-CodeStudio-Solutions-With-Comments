#define MOD 1000000007

class Solution {
public:
    // Recursion: Gives TLE
    int solve(int dice, int face, int target)
    {
        // Base Cases:
        if(target < 0) return 0;

        // dices become zero -> not possible
        if(dice == 0 && target != 0) return 0;

        // target zero but dices are not zero:
        if(target == 0 && dice != 0) return 0;

        // Possible case when both target and dices are zero:
        if(target == 0 && dice == 0) return 1;

        int ans = 0;
        // recursively calling for each face of each dice:
        for(int i=1; i<=face; i++)
        {
            ans = (ans % MOD + solve(dice-1, face, target-i)  % MOD) % MOD;
        }

        return ans;
    }

    // Memorisation: TC = O(dice * target * face) and SC = O(dice * target) + O(fx)
    int solve2(int dice, int face, int target, vector<vector<int>>& dp)
    {
        // Base Cases:
        if(target < 0) return 0;

        // dices become zero -> not possible
        if(dice == 0 && target != 0) return 0;

        // target zero but dices are not zero:
        if(target == 0 && dice != 0) return 0;

        // Possible case when both target and dices are zero:
        if(target == 0 && dice == 0) return 1;

        if(dp[dice][target] != -1) return dp[dice][target];

        int ans = 0;
        // recursively calling for each face of each dice:
        for(int i=1; i<=face; i++)
        {
            ans = (ans % MOD + solve2(dice-1, face, target-i, dp)  % MOD) % MOD;
        }

        dp[dice][target] = ans;

        return ans;
    }

    // Tabulation: TC = O(dice * target * face) and SC = O(dice * target)
    int solve3(int dice, int face, int target)
    {
        // Creating 2d dp vector:
        vector<vector<int>> dp (dice+1, vector<int> (target+1, 0));

        // Base case handle:
        dp[0][0] = 1;

        // recursively calling for each face of each dice:
        for(int d=1; d<=dice; d++)
        {
            for(int t=1; t<=target; t++)
            {
                int ans = 0;
                for(int i=1; i<=face; i++)
                {
                    if(t-i >= 0)
                        ans = (ans % MOD + dp[d-1][t-i] % MOD) % MOD;
                }    
                dp[d][t] = ans;
            }
        }

        return dp[dice][target];
    }

    // Space Optimisation: TC = O(dice * target * face) and SC = O(target)
    int solve4(int dice, int face, int target)
    {
        // Creating 2d dp vector:
        vector<int> curr (target+1, 0);
        vector<int> prev (target+1, 0);
        // Base case handle:
        prev[0] = 1;

        // recursively calling for each face of each dice:
        for(int d=1; d<=dice; d++)
        {
            for(int t=1; t<=target; t++)
            {
                int ans = 0;
                for(int i=1; i<=face; i++)
                {
                    if(t-i >= 0)
                        ans = (ans % MOD + prev[t-i] % MOD) % MOD;
                }    
                curr[t] = ans;
            }
            prev = curr;
        }

        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solve(n, k, target);

        // Memorsiation:
        // vector<vector<int>> dp (n+1, vector<int> (target+1, -1));
        // return solve2(n, k, target, dp);

        // Tabulation:
        // return solve3(n, k, target);

        // Space Optimisation:
        return solve4(n, k, target);
    }
};