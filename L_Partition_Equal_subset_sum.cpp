class Solution {
public:
    // Recursion:  Gives TLE:
    int solve(vector<int>& nums, int target, int index)
    {
        // Bases Cases:
        if(index >= nums.size()) return false;
        if(target < 0) return false;
        // possible case:
        if(target == 0) return true;

        int include = solve(nums, target-nums[index], index+1);
        int exclude = solve(nums, target, index+1);

        int ans = include || exclude;

        return ans;
    }

    // Memorisation:
    int solve2(vector<int>& nums, int target, int index, vector<vector<int>>& dp)
    {
        // Bases Cases:
        if(index >= nums.size()) return false;
        if(target < 0) return false;
        // possible case:
        if(target == 0) return true;

        // checking for dp:
        if(dp[index][target] != -1) return dp[index][target];

        int include = solve2(nums, target-nums[index], index+1, dp);
        int exclude = solve2(nums, target, index+1, dp);

        int ans = include || exclude;

        // storing in dp vector:
        dp[index][target] = ans;

        return ans;
    }

    // Tabulation:
    int solve3(vector<int>& nums, int target)
    {
        // Initializing 2d vector:
        vector<vector<bool>> dp (nums.size()+1, vector<bool> (target+1, false));

        // Handling base case:
        for(int i=0; i<=nums.size(); i++)
        {
            dp[i][0] = true;
        }

        // Handling recursive cases:
        for(int index=nums.size()-1; index>=0; index--)
        {
            for(int t=0; t<=target; t++)
            {
                int include = false;
                if(t-nums[index] >= 0)
                    include = dp[index+1][t-nums[index]];
                int exclude = dp[index+1][t];

                int ans = include || exclude;
                dp[index][t] = ans;
            }
        }

        return dp[0][target];
    }

    // Space Optimisation:
    int solve4(vector<int>& nums, int target)
    {
        // Initializing of vectors:
        vector<bool> curr (target+1, false);
        vector<bool> next (target+1, false);

        // Handling base case:
        curr[0] = true;
        next[0] = true;

        // Handling recursive cases:
        for(int index=nums.size()-1; index>=0; index--)
        {
            for(int t=0; t<=target; t++)
            {
                int include = false;
                if(t-nums[index] >= 0)
                    include = next[t-nums[index]];
                int exclude = next[t];

                int ans = include || exclude;
                curr[t] = ans;
            }
            next = curr;
        }

        return next[target];
    }

    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i=0; i<nums.size(); i++)
        {
            target += nums[i];
        }
        // odd sum of all the elements -> return false
        if(target % 2 != 0) return false;
        // return solve(nums, target / 2, 0);

        // Memorisation:
        // vector<vector<int>> dp (nums.size(), vector<int> (target/2+1, -1));
        // return solve2(nums, target/2, 0, dp);

        // Tabulation:
        // return solve3(nums, target/2);

        // Space Optimisation:
        return solve4(nums, target/2);
    }
};