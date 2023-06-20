class Solution {
public:
    // Recursion: Gives TLE
    // int solve(vector<int>& obstacles, int currPos, int currLane)
    // {
    //     // Base Case:
    //     if(currPos == obstacles.size()-1) return 0;

    //     // if there is no obstacle ahead in the same lane:
    //     if(obstacles[currPos+1] != currLane)
    //     {
    //         return solve(obstacles, currPos+1, currLane);
    //     }

    //     // if there is obstacle in the same lane:
    //     else
    //     {
    //         int jumps = INT_MAX;
    //         for(int i=1; i<=3; i++)
    //         {
    //             // checking for obstacles in the jumping lane:
    //             if(currLane != i && obstacles[currPos] != i)
    //                 jumps = min(jumps, 1 + solve(obstacles, currPos+1, i));
    //         }
    //         return jumps;
    //     } 
    // }

    // Memorisation:
    int solve2(vector<int>& obstacles, int currPos, int currLane, vector<vector<int>>& dp)
    {
        // Base Case:
        if(currPos == obstacles.size()-1) return 0;

        // returning ans if found in dp vector:
        if(dp[currLane][currPos] != 0) return dp[currLane][currPos];

        // if there is no obstacle ahead in the same lane:
        if(obstacles[currPos+1] != currLane)
        {
            return solve2(obstacles, currPos+1, currLane, dp);
        }

        // if there is obstacle in the same lane:
        else
        {
            int jumps = INT_MAX;
            for(int i=1; i<=3; i++)
            {
                // checking for obstacles in the jumping lane:
                if(currLane != i && obstacles[currPos] != i)
                    jumps = min(jumps, 1 + solve2(obstacles, currPos+1, i, dp));
            }

            // Storing ans in dp vector:
            dp[currLane][currPos] = jumps;

            return dp[currLane][currPos];
        } 
    }

    // Tabulation:
    int solve3(vector<int>& obstacles)
    {
        int n = obstacles.size()-1;

        // Creating dp vector and initializing it:
        vector<vector<int>> dp (4, vector<int> (n+1, 1e9));

        // Handling base case of recursion:
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        // Handling rest of the recursive cases:
        for(int pos=n-1; pos>=0; pos--)
        {
            for(int lane=1; lane<=3; lane++)
            {
                // if there is no obstacle ahead in the same lane:
                if(obstacles[pos+1] != lane)
                {
                    dp[lane][pos] = dp[lane][pos+1];
                }

                // if there is obstacle in the same lane:
                else
                {
                    int jumps = 1e9;
                    for(int i=1; i<=3; i++)
                    {
                        // checking for obstacles in the jumping lane:
                        if(lane != i && obstacles[pos] != i)
                            jumps = min(jumps, 1 + dp[i][pos+1]);
                    }

                    // Storing ans in dp vector:
                    dp[lane][pos] = jumps;
                } 
            }
        }

        int ans = min(dp[1][0] + 1, min(dp[2][0], dp[3][0] + 1));

        return ans;
    }

    // Space Optimisation: TC = O(n) and SC = O(1)
    int solve4(vector<int>& obstacles)
    {
        int n = obstacles.size()-1;

        // Creating 2 1d dp vectors and initializing them:
        vector<int> nextColumn (4, 0);
        vector<int> currColumn (4, 1e9);

        // Handling rest of the recursive cases:
        for(int pos=n-1; pos>=0; pos--)
        {
            for(int lane=1; lane<=3; lane++)
            {
                // if there is no obstacle ahead in the same lane:
                if(obstacles[pos+1] != lane)
                {
                    currColumn[lane] = nextColumn[lane];
                }

                // if there is obstacle in the same lane:
                else
                {
                    int jumps = 1e9;
                    for(int i=1; i<=3; i++)
                    {
                        // checking for obstacles in the jumping lane:
                        if(lane != i && obstacles[pos] != i)
                            jumps = min(jumps, 1 + nextColumn[i]);
                    }

                    // Storing ans in currColumn vector:
                    currColumn[lane] = jumps;
                } 
            }

            // copying currColumn int nextColumn:
            nextColumn = currColumn;
        }

        int ans = min(nextColumn[1] + 1, min(nextColumn[2], nextColumn[3] + 1));

        return ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        // Recursion:
        // return solve(obstacles, 0, 2);

        // Memorisation:
        // vector<vector<int>> dp (4, vector<int> (obstacles.size() + 1, 0));
        // return solve2(obstacles, 0, 2, dp);

        // Tabulation:
        // return solve3(obstacles);

        // Space Optimisation:
        return solve4(obstacles);
    }
};