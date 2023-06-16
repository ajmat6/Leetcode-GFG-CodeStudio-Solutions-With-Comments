class Solution {
public:
    // int maxAdjSum(vector<int>& nums, int index, int& sum)
    // {
    //     // Base Case
    //     if(index >= nums.size()) return 0;

    //     // Including current Index:
    //     int maxSum;

    //     maxSum = max(maxAdjSum(nums, index+2, sum), maxAdjSum(nums, index+3, sum)) + nums[index];

    //     return maxSum;
    // }

    // // Memorisation: TC = O(n), SC = O(n)
    // int maxAdjSum2(vector<int>& nums, vector<int>& dp, int index)
    // {
    //     // Base Case
    //     if(index >= nums.size()) return 0;

    //     // checking through dp:
    //     if(dp[index] != -1) return dp[index];

    //     // Storing in dp:
    //     dp[index] = max(maxAdjSum2(nums, dp, index+2), maxAdjSum2(nums, dp, index+3)) + nums[index];

    //     return dp[index];
    // }

    // // Tabulation: TC = O(n), SC = O(n)
    // int maxAdjSum3(vector<int>& nums)
    // {
    //     int n = nums.size();

    //     // Base Cases:
    //     if(n == 1) return nums[0];
    //     if(n == 2) return max(nums[0], nums[1]);

    //     // Creating dp vector and initializing it:
    //     vector<int> dp(nums.size(), -1);
    //     dp[n-1] = nums[n-1];
    //     dp[n-2] = nums[n-2];
    //     dp[n-3] = nums[n-3] + nums[n-1];

    //     // logic for rest of the members of dp vector:
    //     for(int i=n-4; i>=0; i--)
    //     {
    //         dp[i] = max(dp[i+2], dp[i+3]) + nums[i];
    //     }

    //     return max(dp[0], dp[1]);
    // }

    // // Space Optimisation: TC = O(n), SC = O(1)
    int maxAdjSum4(vector<int>& nums)
    {
        int n = nums.size();

        // Base Cases:
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int curr;
        int next3 = nums[n-1];
        int next2 = nums[n-2];
        int next1 = nums[n-3] + nums[n-1];

        for(int i=n-4; i>=0; i--)
        {
            int curr = max(next2, next3) + nums[i];
            next3 = next2;
            next2 = next1;
            next1 = curr;
        }

        return max(next1, next2);
    }

    int rob(vector<int>& nums) {
        // int sum = 0;
        // sum = max(maxAdjSum(nums, 0, sum), maxAdjSum(nums, 1, sum));
        // return sum;

        // Memorisation:
        // int sum = 0;
        // vector<int> dp(nums.size()+1, -1);
        // sum = max(maxAdjSum2(nums, dp, 0), maxAdjSum2(nums, dp, 1));
        // return sum;

        // Tabulation:
        // return maxAdjSum3(nums);

        // Space Optimisation:
        return maxAdjSum4(nums);
    }
};