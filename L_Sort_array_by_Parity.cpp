class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0; 
        int high = nums.size() - 1;

        while(low < high)
        {
            if((nums[low] % 2 != 0) && (nums[high] % 2 == 0))
            {
                int temp = nums[low];
                nums[low] = nums[high];
                nums[high] = temp;

                low++;
                high--;
            }

            else if((nums[low] % 2 != 0) && (nums[high] % 2 != 0)) high--;

            else if((nums[low] % 2 == 0) && (nums[high] % 2 == 0)) low++;

            else 
            {
                low++;
                high--;
            }
        }
        return nums;
    }
};