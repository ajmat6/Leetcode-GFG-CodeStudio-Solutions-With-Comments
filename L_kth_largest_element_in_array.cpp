class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Make a Min heap of size k (so that its top element will be kth largest element)
        priority_queue<int, vector<int>, greater<int> > ajmat;
        for(int i=0; i<k; i++)
        {
            ajmat.push(nums[i]);
        }

        // Now check for the rest of the elements in the vector 
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i] > ajmat.top())
            {
                ajmat.pop(); // pop top element as greater element is found
                ajmat.push(nums[i]);
            }
        }

        return ajmat.top();
    }
};