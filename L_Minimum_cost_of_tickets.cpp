class Solution {
public:
    // Recursive - Gives TLE
    // int solve(vector<int>& days, vector<int>& costs, int dayno)
    // {
    //     if(dayno >= days.size()) return 0;
        
    //     // one day pass:
    //     int oneDay = solve(days, costs, dayno+1) + costs[0];

    //     // seven day pass:
    //     int i;
    //     for(i = dayno; i<days.size() && days[i] < days[dayno] + 7; i++);
    //     int sevenDay = solve(days, costs, i) + costs[1];

    //     // thirty day pass:
    //     for(i = dayno; i<days.size() && days[i] < days[dayno] + 30; i++);
    //     int thirtyDay = solve(days, costs, i) + costs[2]; 

    //     int ans = min(oneDay, min(sevenDay, thirtyDay));
    //     return ans;
    // }

    // Memorisation:
    // int solve2(vector<int>& days, vector<int>& costs, int dayno, vector<int>& dp)
    // {
    //     if(dayno >= days.size()) return 0;
        
    //     // one day pass:
    //     int oneDay = solve2(days, costs, dayno+1, dp) + costs[0];

    //     // checking for dp:
    //     if(dp[dayno] != -1) return dp[dayno];

    //     // seven day pass:
    //     int i;
    //     for(i = dayno; i<days.size() && days[i] < days[dayno] + 7; i++);
    //     int sevenDay = solve2(days, costs, i, dp) + costs[1];

    //     // thirty day pass:
    //     for(i = dayno; i<days.size() && days[i] < days[dayno] + 30; i++);
    //     int thirtyDay = solve2(days, costs, i, dp) + costs[2];

    //     int ans = min(oneDay, min(sevenDay, thirtyDay));
    //     return dp[dayno] = ans;
    // }

    // // Tabulation:
    // int solve3(vector<int>& days, vector<int>& costs)
    // {
    //     vector<int> dp(days.size() + 1, INT_MAX);
    //     dp[days.size()] = 0;

    //     for(int k=days.size()-1; k>=0; k--)
    //     {
    //         // one day pass:
    //         int oneDay = dp[k+1] + costs[0];

    //         // seven day pass:
    //         int i;
    //         for(i = k; i<days.size() && days[i] < days[k] + 7; i++);
    //         int sevenDay = dp[i] + costs[1];

    //         // thirty day pass:
    //         for(i = k; i<days.size() && days[i] < days[k] + 30; i++);
    //         int thirtyDay = dp[i] + costs[2];

    //         dp[k] = min(oneDay, min(sevenDay, thirtyDay));
    //     }
    //     return dp[0];
    // }

    // Space Optimisation: SC = O(1)
    int solve4(vector<int>& days, vector<int>& costs)
    {
        int ans = 0;
        queue<pair<int, int>> weekly;
        queue<pair<int, int>> monthly;

        for(int day: days)
        {
            // Pop from the queue if the queue's front element is not meeting the below condition:
            while(!weekly.empty() && weekly.front().first + 7 <= day)
            {
                weekly.pop();
            }

            while(!monthly.empty() && monthly.front().first + 30 <= day)
            {
                monthly.pop();
            }

            // Push into the queue:
            weekly.push({day, ans + costs[1]});
            monthly.push({day, ans + costs[2]});

            // update the ans:
            ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
        }

        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solve(days, costs, 0);

        // Memorisation:
        // vector<int> dp(days.size(), -1);
        // return solve2(days, costs, 0, dp);

        // Tabulation:
        // return solve3(days, costs);

        // Space Optimisation:
        return solve4(days, costs);
    }
};