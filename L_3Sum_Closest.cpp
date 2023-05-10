class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int value = 0;
        int diff = INT_MAX;
        for(int i=0; i<nums.size(); i++)
        {
            int low = i + 1;
            int high = nums.size() - 1;

            while(low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                int difference = abs(sum - target);

                if(difference < diff)
                {
                    diff = difference;
                    value = sum;
                }

                if(sum == target) return sum;
                else if(sum > target) high --;
                else low++;
            }
        }
        return value;
    }
};