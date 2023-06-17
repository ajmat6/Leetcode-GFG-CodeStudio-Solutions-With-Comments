class Solution {
public:
    // Recursive: Gives TLE
    // int solve(vector<int>&  nums, int target)
    // {
    //     if(target == 0) return 1;
    //     if(target < 0) return 0;

    //     int ans = 0;
    //     for(int i=0; i<nums.size(); i++)
    //     {
    //         ans += solve(nums, target-nums[i]);
    //     }

    //     return ans;
    // }

    // Memorisation:
    int solve2(vector<int>&  nums, int target, vector<int>& dp)
    {
        // Base Case:
        if(target == 0) return 1;
        if(target < 0) return 0;

        // Checking for value if avialable:
        if(dp[target] != -1) return dp[target];

        // Storing the ans for each target value:
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += solve2(nums, target-nums[i], dp);
        }

        // Storing ans in dp for memorisation:
        dp[target] = ans;

        return dp[target];
    }

    // Tabulation:
    // int solve3(vector<int>&  nums, int target)
    // {
    //     // Creating and Initializing dp vector:
    //     vector<unsigned int> dp(target+1, 0);
    //     dp[0] = 1;
        
    //     for(int i=1; i<=target; i++)
    //     {
    //         for(int j=0; j<nums.size(); j++)
    //         {
    //             if(i-nums[j] >= 0)
    //                 dp[i] += dp[i-nums[j]];
    //         }
    //     }

    //     return dp[target];
    // }

    int combinationSum4(vector<int>& nums, int target) {
        // Recursive:
        // return solve(nums, target);

        // Memorisation:
        vector<int> dp(target+1, -1);
        return solve2(nums, target, dp);

        // Tabulation:
        // return solve3(nums, target);
    }
};