class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //Sorting the array
        sort(nums.begin(), nums.end());

        //Storing the max element
        int max = nums[nums.size() - 1];

        //Search for the third distinct maximum element
        int thirdMax = max;
        int count = 1;

        for(int i=nums.size()-1; i>=0; i--)
        {
            if(count == 3) break;
            else if(nums[i]<thirdMax)
            {
                thirdMax = nums[i];
                count++;
            }
        }

        //if third max element is found return that else return max element in the array
        if(count == 3) return thirdMax;
        else return max;
    }
};