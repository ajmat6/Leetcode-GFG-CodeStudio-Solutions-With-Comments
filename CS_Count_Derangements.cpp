#define MOD 1000000007 // Defining modulus value
#include<vector>

int solve(int n)
{
    // Base case:
    if(n == 1) return 0;
    if(n == 2) return 1;

    // As there n-1 possible places for an element to be placed and for each place, elements can swap each other and may not do do:
    int ans = ((n-1) * (solve(n-2) + solve(n-1))) % MOD;
    return ans;
}

// Memorisation:
long long solve2(int n, vector<long long>& dp)
{
    // Base case:
    if(n == 1) return 0;
    if(n == 2) return 1;

    if(dp[n] != -1) return dp[n];

    // As there n-1 possible places for an element to be placed and for each place, elements can swap each other and may not do do:
    dp[n] = ((n-1)%MOD * (solve2(n-2, dp)%MOD + solve2(n-1, dp)%MOD)) % MOD;
    return dp[n];
}

long long solve3(int n)
{
    // Create dp vector and initializing it:
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++)
    {
        long long first = dp[i-1]%MOD;
        long long second = dp[i-2]%MOD;
        long long sum = (first + second) % MOD;

        dp[i] = ((i-1)%MOD * sum) % MOD;
    }

    return dp[n];
}

// Space Optimisation:
long long solve4(int n)
{
    long long prev1 = 1;
    long long prev2 = 0;
    int curr;

    for(int i=3; i<=n; i++)
    {
        long long first = prev1%MOD;
        long long second = prev2%MOD;
        long long sum = (first + second) % MOD;

        curr = ((i-1)%MOD * sum) % MOD;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int countDerangements(int n) {
    // return solve(n);

    // Memorisation:
    // vector<long long> dp(n+1, -1);
    // return solve2(n, dp);

    // Tabulation
    // return solve3(n);

    // Space Optimisation
    return solve4(n);
}