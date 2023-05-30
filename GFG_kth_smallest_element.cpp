#include<queue>
class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        // Make a Min heap of size k (so that its top element will be kth largest element)
        priority_queue<int> ajmat;
        for(int i=l; i<k; i++)
        {
            ajmat.push(arr[i]);
        }

        // Now check for the rest of the elements in the vector 
        for(int i=k; i<=r; i++)
        {
            if(arr[i] < ajmat.top())
            {
                ajmat.pop(); // pop top element as greater element is found
                ajmat.push(arr[i]);
            }
        }

        return ajmat.top();
    }
};
