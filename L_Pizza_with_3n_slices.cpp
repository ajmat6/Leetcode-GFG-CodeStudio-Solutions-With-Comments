class Solution {
public:
    // Recursive:   
    int solve(vector<int>& slices, int index, int eat, int endIndex)
    {
        // Base case:
        if(eat == 0 || index > endIndex) return 0;

        // if you are eating current index slice:
        int includeCurrSlice = solve(slices, index+2, eat-1, endIndex) + slices[index];

        // if you are not eating current index slice:
        int excludeCurrSlide = solve(slices, index+1, eat, endIndex) + 0;

        int ans = max(includeCurrSlice, excludeCurrSlide);
        return ans;
    }

    // Memorisation:   
    int solve2(vector<int>& slices, int index, int eat, int endIndex, vector<vector<int>>& dp)
    {
        // Base case:
        if(eat == 0 || index > endIndex) return 0;

        // checking for dp:
        if(dp[index][eat] != -1) return dp[index][eat];

        // if you are eating current index slice:
        int includeCurrSlice = solve2(slices, index+2, eat-1, endIndex, dp) + slices[index];

        // if you are not eating current index slice:
        int excludeCurrSlide = solve2(slices, index+1, eat, endIndex, dp) + 0;

        int ans = max(includeCurrSlice, excludeCurrSlide);

        // storing in dp:
        dp[index][eat] = ans;

        return dp[index][eat];
    }

    // Tabulation:
    int solve3(vector<int>& slices)
    {
        int n = slices.size();
        // creating dp vectors:
        vector<vector<int>> dp1(n+2, vector<int> (n/3+1, 0));

        // Case 1 -> you will eat first slice:
        for(int index=n-2; index>=0; index--)
        {
            for(int eat=1; eat<=n/3; eat++)
            {
                // if you are eating current index slice:
                int includeCurrSlice = dp1[index+2][eat-1] + slices[index];

                // if you are not eating current index slice:
                int excludeCurrSlide = dp1[index+1][eat] + 0;

                dp1[index][eat] = max(includeCurrSlice, excludeCurrSlide);
            }
        }
        
        vector<vector<int>> dp2(n+2, vector<int> (n/3+1, 0));

        // Case 2 -> you will not eat first slice:

        for(int index=n-1; index>=1; index--)
        {
            for(int eat=1; eat<=n/3; eat++)
            {
                // if you are eating current index slice:
                int includeCurrSlice = dp2[index+2][eat-1] + slices[index];

                // if you are not eating current index slice:
                int excludeCurrSlide = dp2[index+1][eat] + 0;

                dp2[index][eat] = max(includeCurrSlice, excludeCurrSlide);
            }
        }

        return max(dp1[0][n/3], dp2[1][n/3]);
    }

    // Space Optimisation:
    int solve4(vector<int>& slices)
    {
        int n = slices.size();
        // creating dp vectors:
        vector<int> curr1 (n/3+1, 0);
        vector<int> next1 (n/3+1, 0);
        vector<int> next2 (n/3+1, 0);

        // Case 1 -> you will eat first slice:
        for(int index=n-2; index>=0; index--)
        {
            for(int eat=1; eat<=n/3; eat++)
            {
                // if you are eating current index slice:
                int includeCurrSlice = next2[eat-1] + slices[index];

                // if you are not eating current index slice:
                int excludeCurrSlide = next1[eat] + 0;

                curr1[eat] = max(includeCurrSlice, excludeCurrSlide);
            }

            next2 = next1;
            next1 = curr1;
        }
        
        // creating dp vectors:
        vector<int> currr1 (n/3+1, 0);
        vector<int> nextt1 (n/3+1, 0);
        vector<int> nextt2 (n/3+1, 0);

        // Case 2 -> you will not eat first slice:

        for(int index=n-1; index>=1; index--)
        {
            for(int eat=1; eat<=n/3; eat++)
            {
                // if you are eating current index slice:
                int includeCurrSlice = nextt2[eat-1] + slices[index];

                // if you are not eating current index slice:
                int excludeCurrSlide = nextt1[eat] + 0;

                currr1[eat] = max(includeCurrSlice, excludeCurrSlide);
            }

            nextt2 = nextt1;
            nextt1 = currr1;
        }

        return max(next1[n/3], nextt1[n/3]);
    }

    int maxSizeSlices(vector<int>& slices) {
        // int n = slices.size();
        // // slices I have to eat:
        // int eat = n / 3;
        // // case 1 one I will eat first slice(0th index):
        // int ans1 = solve(slices, 0, eat, n-2);
        // // case 1 one I will not eat first slice(0th index):
        // int ans2 = solve(slices, 1, eat, n-1);
        // // return max of both the answers:
        // return max(ans1, ans2);

        // Memorisation:
        // int n = slices.size();
        // vector<vector<int>> dp1(n, vector<int> (n/3+1, -1));
        // // slices I have to eat:
        // int eat = n / 3;
        // // case 1  I will eat first slice(0th index):
        // int ans1 = solve2(slices, 0, eat, n-2, dp1);
        // // making another dp array for case 2
        // vector<vector<int>> dp2(n, vector<int> (n+1, -1));
        // // case 2  I will not eat first slice(0th index):
        // int ans2 = solve2(slices, 1, eat, n-1, dp2);
        // // return max of both the answers:
        // return max(ans1, ans2);

        // Tabulation:
        // return solve3(slices);

        // Space Optimisation:
        return solve4(slices);
    }
};