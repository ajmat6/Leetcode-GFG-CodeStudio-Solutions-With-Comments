#include<bits/stdc++.h>

int solve(int n, int x, int y, int z)
{
	if(n == 0) return 0;

	if(n < 0) return INT_MIN;

	int maxSegments = INT_MIN;

	int xDivide = solve(n-x, x, y, z);
	int yDivide = solve(n-y, x, y, z);
	int zDivide = solve(n-z, x, y, z);

	if(xDivide != INT_MIN) maxSegments = max(maxSegments, xDivide + 1);
	if(yDivide != INT_MIN) maxSegments = max(maxSegments, yDivide + 1);
	if(zDivide != INT_MIN) maxSegments = max(maxSegments, zDivide + 1);

	return maxSegments;
}

// Memorisation:
int solve2(int n, int x, int y, int z, vector<int>& dp)
{
	// Base Cases
	if(n == 0) return 0;

	if(n < 0) return INT_MIN;

	// if value is already present in the dp vector return it don't call recursion:
	if(dp[n] != -1) return dp[n];

	int maxSegments = INT_MIN;

	// finding segments for each length
	int xDivide = solve2(n-x, x, y, z, dp);
	int yDivide = solve2(n-y, x, y, z, dp);
	int zDivide = solve2(n-z, x, y, z, dp);


	if(xDivide != INT_MIN) maxSegments = max(maxSegments, xDivide + 1);
	if(yDivide != INT_MIN) maxSegments = max(maxSegments, yDivide + 1);
	if(zDivide != INT_MIN) maxSegments = max(maxSegments, zDivide + 1);

	// memorising
	dp[n] = maxSegments;

	return dp[n];
}

// Tabulation:
int solve3(int n, int x, int y, int z)
{
	// Creating and initializing the dp vector:
	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;

	for(int i=1; i<=n; i++)
	{
		if(i-x >= 0 && dp[i-x] != INT_MIN)
			dp[i] = max(dp[i], dp[i-x] + 1);
		if(i-y >= 0 && dp[i-y] != INT_MIN)
			dp[i] = max(dp[i], dp[i-y] + 1);
		if(i-z >= 0 && dp[i-z] != INT_MIN)
			dp[i] = max(dp[i], dp[i-z] + 1);
	}
	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// int ans = solve(n, x, y, z);
	// if(ans == INT_MIN) return 0;
	// return ans;

	// Memorisation:
	// vector<int> dp(n+1, -1);
	// int ans = solve2(n, x, y, z, dp);
	// if(ans == INT_MIN) return 0;
	// return ans;

	// Tabulation:
	int ans = solve3(n, x, y, z);
	if(ans == INT_MIN) return 0;
	return ans;
}