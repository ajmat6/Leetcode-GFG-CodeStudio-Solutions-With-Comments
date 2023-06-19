class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        // making a set for unique answers:
        set<vector<int>> s;

        // Sorting vector for applying binary search:
        sort(nums.begin(), nums.end());

        // Two pointer logic:
        for(int i=0; i<nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() -1;

            // binary search
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                else if(sum < 0) j++;
                else k--;
            }
        }

        // pushing unique answers into the ans vector:
        for(auto i: s) ans.push_back(i);

        return ans;
    }
};