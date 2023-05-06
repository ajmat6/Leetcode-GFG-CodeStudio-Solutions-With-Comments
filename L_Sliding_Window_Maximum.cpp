class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> d;
        int max = INT_MIN;

        if(k == 1) return nums;

        //finding max element in first window                  
        for(int i=0; i<k; i++)
        {
          while(!d.empty() && nums[i] >= nums[d.back()]) d.pop_back();
          d.push_back(i); 
        }
        
        //pushing first window max element into the answer vector
        ans.push_back(nums[d.front()]);

        //loops for the rest of the window
        for(int i=k; i<nums.size(); i++)
        {
            //popping the front index if it out of the range
            if(i-d.front() >= k)
            {
                d.pop_front();
            }

            //bringing max element in the front
            while(!d.empty() && nums[i] >= nums[d.back()]) d.pop_back();
            d.push_back(i);

            //pushing max element of each window
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};