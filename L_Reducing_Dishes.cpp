class Solution {
public:
    // Recursinve solution: Gives TLE
    int solve(vector<int>& s, int i, int time)
    {
        // Base Case;
        if(i == s.size()) return 0;

        int include = solve(s, i+1, time+1) + s[i] * time;
        int exclude = solve(s, i+1, time) + 0;

        int ans = max(include, exclude);
        return ans;
    }

    // Memorisation: TC = O(n^2) and SC = O(n^2)
    int solve2(vector<int>& s, int i, int time, vector<vector<int>>& dp)
    {
        // Base Case;
        if(i == s.size()) return 0;

        // dp check:
        if(dp[i][time] != -1) return dp[i][time];

        int include = solve2(s, i+1, time+1, dp) + s[i] * time;
        int exclude = solve2(s, i+1, time, dp) + 0;

        int ans = max(include, exclude);

        // storing in dp:
        dp[i][time] = ans;

        return dp[i][time];
    }

    // Tabulation: TC = O(n^2) and SC = O(n^2)
    int solve3(vector<int>& s)
    {
        int n = s.size();
        // Creating dp vector and initializing it:
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        // Handling cases of recursion:
        for(int index=n-1; index>=0; index--)
        {
            for(int time=index; time>=0; time--)
            {
                int include = dp[index+1][time+1] + s[index] * (time+1);
                int exclude = dp[index+1][time] + 0;

                int ans = max(include, exclude);

                // storing in dp:
                dp[index][time] = ans;
            }  
        }

        return dp[0][0];
    }

    // Space Optimisation: SC = O(n)
    int solve4(vector<int>& s)
    {
        int n = s.size();
        // Creating curr and next vectors and initializing them:
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        // Handling cases of recursion:
        for(int index=n-1; index>=0; index--)
        {
            for(int time=index; time>=0; time--)
            {
                int include = next[time+1] + s[index] * (time+1);
                int exclude = next[time] + 0;

                int ans = max(include, exclude);

                // storing in next vector:
                curr[time] = ans;                
            }  
            // making curr equal to next:
            next = curr;
        }

        return curr[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // Recursive:
        // sorting to make LT coefficient lower for the low satisfied dishes
        // sort(satisfaction.begin(), satisfaction.end());
        // return solve(satisfaction, 0, 1);

        // Memorisation:
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // sort(satisfaction.begin(), satisfaction.end());
        // return solve2(satisfaction, 0, 1, dp);

        // Tabulation:
        // sort(satisfaction.begin(), satisfaction.end());
        // return solve3(satisfaction);

        // Space Optimisation:
        sort(satisfaction.begin(), satisfaction.end());
        return solve4(satisfaction);
    }
};