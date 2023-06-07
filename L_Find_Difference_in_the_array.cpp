class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // storing nums1 and nums2 unique values in the set:
        set<int> nums1Values (nums1.begin(), nums1.end());
        set<int> nums2Values (nums2.begin(), nums2.end());

        vector<int> nums1Diff;
        vector<int> nums2Diff;

        // checking for the absence of num1 values in nums2
        for(auto i: nums1Values)
        {
            if(nums2Values.count(i) == 0)
            {
                nums1Diff.push_back(i);
            }
        }

        // checking for the absence of num2 values in nums1
        for(auto i: nums2Values)
        {
            if(nums1Values.count(i) == 0)
            {
                nums2Diff.push_back(i);
            }
        }

        return {nums1Diff, nums2Diff};
    }
};