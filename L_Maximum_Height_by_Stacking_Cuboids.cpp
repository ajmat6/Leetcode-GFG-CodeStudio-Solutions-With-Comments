class Solution {
public:
    bool check (vector<int>& a, vector<int>& b)
    {
        if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) return true;
        else return false;
    }

    int solve(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
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
                if(prev < 0 || check(cuboids[curr], cuboids[prev]))
                {
                    include = cuboids[curr][2] + next[curr+1];
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

    int maxHeight(vector<vector<int>>& cuboids) {
        // Sorting each vector in 2d vector:
        for(auto &i: cuboids)
        {
            sort(i.begin(), i.end());
        }

        // Sort 2d vector on the basis of the width
        sort(cuboids.begin(), cuboids.end());

        // Apply longest incresing subsequence:
        return solve(cuboids);
    }
};L