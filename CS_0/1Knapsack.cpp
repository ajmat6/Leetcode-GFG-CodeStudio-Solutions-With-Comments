#include <bits/stdc++.h> 


// Recursive -> Gives TLE (Exponential Time Complexity)
// int solve(vector<int>& weight, vector<int>& value, int i, int maxWeight)
// {
// 	// Base Case:
// 	if(i == 0)
// 	{
// 		// Checking for the weight capacity:
// 		if(weight[0] <= maxWeight) return value[0];
// 		else return 0;
// 	}

// 	// Include Case of each weight (call for next weight by decreasing the maxWeight with the current index weight):
// 	int include = 0;
// 	if(weight[i] <= maxWeight)
// 	{
// 		include = solve(weight, value, i-1, maxWeight - weight[i]) + value[i];
// 	}

// 	// Exclude Case of each Weight:
// 	int exclude = solve(weight, value, i-1, maxWeight) + 0;

// 	return max(include, exclude);
// }

// Memorisation: TC = O(n*maxWeight) SC is same
int solve2(vector<int>& weight, vector<int>& value, int i, int maxWeight, vector<vector<int>>& dp)
{
	// Base Case:
	if(i == 0)
	{
		// Checking for the weight capacity:
		if(weight[0] <= maxWeight) return value[0];
		else return 0;
	}

	// Checking for dp:
	if(dp[i][maxWeight] != -1) return dp[i][maxWeight];

	// Include Case of each weight (call for next weight by decreasing the maxWeight with the current index weight):
	int include = 0;
	if(weight[i] <= maxWeight)
	{
		include = solve2(weight, value, i-1, maxWeight - weight[i], dp) + value[i];
	}

	// Exclude Case of each Weight:
	int exclude = solve2(weight, value, i-1, maxWeight, dp) + 0;

	// Storing ans in dp:
	dp[i][maxWeight] = max(include, exclude);

	return dp[i][maxWeight];
}

// Tabulation: same TC and SC = O(n*maxWeight)
int solve3(vector<int>& weight, vector<int>& value, int maxWeight)
{
	// Creating 2D DP and initializing it:
	vector<vector<int>> dp(weight.size(), vector<int> (maxWeight+1, 0));

	// Initializing dp vector for the base case in recursion:
	for(int w=weight[0]; w<=maxWeight; w++)
	{
		if(weight[0] <= w)
		{
			dp[0][w] = value[0];
		}
		else dp[0][w] = 0;
	}

	// Rest of the cases in tabulation (Recursive calls in recursive ans):
	for(int i=1; i<dp.size(); i++)
	{
		for(int w=0; w<= maxWeight; w++)
		{
			int include = 0;
			if(weight[i] <= w)
				include = dp[i-1][w-weight[i]] + value[i];

			int exclude = dp[i-1][w] + 0;

			dp[i][w] = max(include, exclude);
		}
	}

	return dp[weight.size()-1][maxWeight];
}

// Space Optimisation: SC = O(2 * maxWeight) where n is the size of the weight vector and same TC:
int solve4(vector<int>& weight, vector<int>& value, int maxWeight)
{
	// Creating 2 1d vectors and initializing them:
	vector<int> prev (maxWeight+1, 0);
	vector<int> curr (maxWeight+1, 0);

	// Initializing dp vector for the base case in recursion:
	for(int w=weight[0]; w<=maxWeight; w++)
	{
		if(weight[0] <= w)
		{
			prev[w] = value[0];
		}
		else prev[w] = 0;
	}

	// Rest of the cases in tabulation (Recursive calls in recursive ans):
	for(int i=1; i<weight.size(); i++)
	{
		for(int w=0; w<=maxWeight; w++)
		{
			int include = 0;
			if(weight[i] <= w)
				include = prev[w-weight[i]] + value[i];

			int exclude = prev[w] + 0;

			curr[w] = max(include, exclude);	
		}
		// prev ko aaghe badhao:
		prev = curr;
	}

	return prev[maxWeight];
}

// More Space Optimisation: SC = O(maxWeight) and same TC:
int solve5(vector<int>& weight, vector<int>& value, int maxWeight)
{
	// Creating 1d vector and initializing them:
	vector<int> curr (maxWeight+1, 0);

	// Initializing dp vector for the base case in recursion:
	for(int w=weight[0]; w<=maxWeight; w++)
	{
		if(weight[0] <= w)
		{
			curr[w] = value[0];
		}
		else curr[w] = 0;
	}

	// Rest of the cases in tabulation (Recursive calls in recursive ans):
	for(int i=1; i<weight.size(); i++)
	{
		for(int w=maxWeight; w>=0; w--)
		{
			int include = 0;
			if(weight[i] <= w)
				include = curr[w-weight[i]] + value[i];

			int exclude = curr[w] + 0;

			curr[w] = max(include, exclude);	
		}
	}

	return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solve(weight, value, n-1, maxWeight);

	// Memorisation with 2D DP:
	// vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	// return solve2(weight, value, n-1, maxWeight, dp);

	// Tabulation:
	// return solve3(weight, value, maxWeight);

	// Space Optimisation:
	// return solve4(weight, value, maxWeight);

	// More Space Optimisation:
	return solve5(weight, value, maxWeight);
}