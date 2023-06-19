class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();

        // sorting nums to perform binary search:
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        // for unique vector sets:
        set<vector<int>> s;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                // Binary Search:
                int low = j + 1;
                int high = n -1;

                while(low < high)
                {
                    // long long for integer overflow:
                    long long targett = (long long)nums[low] + (long long)nums[high] + (long long)nums[i] + (long long)nums[j];
                    if(targett == (long long)target)
                    {
                        s.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }

                    else if(targett < (long long)target)
                    {
                        low++;
                    }

                    else
                    {
                        high--;
                    }
                }
            }
        } 

        // Storing in ans vector:
        for(auto i: s) ans.push_back(i);

        return ans;       
    }
};