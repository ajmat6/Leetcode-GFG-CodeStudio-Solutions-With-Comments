#define MOD 1000000007

// Utility Function:
int add(int a, int b)
{
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b)
{
    return (a%MOD * 1LL * b%MOD)%MOD; // 1LL for int range exceed so typecasting
}

// Recursion
int solve(int n, int k)
{
    // Base Case:
    if(n == 1) return k;

    if(n == 2) return (add(k, mul(k, k-1)));

    int sameColor = solve(n-2, k);
    int diffColor = solve(n-1, k);

    int ans = add(mul(sameColor, k-1), mul(diffColor, k-1));
    return ans;
}

// Memorisation
int solve2(int n, int k, vector<int>& dp)
{
    // Base Case:
    if(n == 1) return k;

    if(n == 2) return (add(k, mul(k, k-1)));

    // dp check:
    if(dp[n] != -1) return dp[n];

    int sameColor = solve2(n-2, k, dp);
    int diffColor = solve2(n-1, k, dp);

    dp[n] = add(mul(sameColor, k-1), mul(diffColor, k-1));
    return dp[n];
}

// Tabulation
int solve3(int n, int k)
{
    // Creating and initializing dp vector:
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i=3; i<=n; i++)
    {
        int sameColor = dp[i-2];
        int diffColor = dp[i-1];

        dp[i] = add(mul(sameColor, k-1), mul(diffColor, k-1));
    }

    return dp[n];
}

// Space Optimisation:
int solve4(int n, int k)
{
    // Creating variables for space optimisation and initializing them:
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    int curr;

    for(int i=3; i<=n; i++)
    {
        int sameColor = prev2;
        int diffColor = prev1;

        curr = add(mul(sameColor, k-1), mul(diffColor, k-1));

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

#include <bits/stdc++.h> 
int numberOfWays(int n, int k) {
    // return solve(n, k);

    // Memorisation:
    // vector<int> dp(n+1, -1);
    // return solve2(n, k, dp);

    // Tabulation:
    // return solve3(n, k);

    // Space Optimisation:
    return solve4(n, k);
}
