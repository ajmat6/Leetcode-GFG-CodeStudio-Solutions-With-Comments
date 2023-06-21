class Solution {
public:
    // Recursion:
    int solve(vector<int>& nums, int currIndex, int prevIndex)
    {
        // Base Case:
        if(currIndex >= nums.size()) return 0;

        // Including current Index:
        int include = 0;
        if(prevIndex < 0 || nums[currIndex] > nums[prevIndex])
        {
            include = 1 + solve(nums, currIndex+1, currIndex);
        }

        // Exclude case:
        int exclude = 0 + solve(nums, currIndex+1, prevIndex);

        int ans = max(include, exclude);
        return ans;
    }

    // Memorisation: TC = O(n^2) and SC = O(n^2)
    int solve2(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp)
    {
        // Base Case:
        if(currIndex >= nums.size()) return 0;

        // check for the dp:
        if(dp[currIndex][prevIndex+1] != -1) return dp[currIndex][prevIndex+1];

        // Including current Index:
        int include = 0;
        if(prevIndex < 0 || nums[currIndex] > nums[prevIndex])
        {
            include = 1 + solve2(nums, currIndex+1, currIndex, dp);
        }

        // Exclude case:
        int exclude = 0 + solve2(nums, currIndex+1, prevIndex, dp);

        int ans = max(include, exclude);

        // storing in dp:
        dp[currIndex][prevIndex+1] = ans;

        return ans;
    }

    // Tabulation:
    int solve3(vector<int>& nums)
    {
        int n = nums.size();
        // Creating dp vector and Initializing it:
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        // Handling recursion:
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                // Including current Index:
                int include = 0;
                if(prev < 0 || nums[curr] > nums[prev])
                {
                    include = 1 + dp[curr+1][curr+1];
                }

                // Exclude case:
                int exclude = 0 + dp[curr+1][prev+1];

                int ans = max(include, exclude);
                dp[curr][prev+1] = ans;
            }
        }
        return dp[0][0];
    }

    // Space Optimisation: Same time and space complexity
    int solve4(vector<int>& nums)
    {
        int n = nums.size();
        // Creating dp vectors and Initializing them:
        vector<int> pre (n+1, 0);
        vector<int> next (n+1, 0);

        // Handling recursion:
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                // Including current Index:
                int include = 0;
                if(prev < 0 || nums[curr] > nums[prev])
                {
                    include = 1 + next[curr+1];
                }

                // Exclude case:
                int exclude = 0 + next[prev+1];

                int ans = max(include, exclude);
                pre[prev+1] = ans;
            }
            next = pre;
        }
        return next[0];
    }

    // Most Optimal solution: TC = O(nlogn) and SC = O(n)
    int solve5(vector<int>& nums)
    {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++)
        {
            // pushing into the vector if it is satisfying LIS condition:
            if(nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }

            // if not find the right position of nums[i] in ans by replacing just greater element than it in ans vector:
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums, 0, -1);

        // Memorisation:
        // int n = nums.size();
        // vector<vector<int>> dp (n, vector<int> (n+1, -1));
        // return solve2(nums, 0, -1, dp);

        // Tabulation:
        // return solve3(nums);

        // Space Optimisation:
        // return solve4(nums);

        // Most Optimised:
        return solve5(nums);
    }
};