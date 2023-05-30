// TC = O(n^2logk) -> n^2 times logk (TC of inserting and popping an element from a heap)
// SC = O(K) -> used by priority queue
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int> > q;
        
        // loops for the track of the subarrays sum
        for(int i=0; i<N; i++)
        {
            int sum = 0;
            for(int j=i; j<N; j++)
            {
                sum += Arr[j];
                
                if(q.size() < K) q.push(sum); // making a group of 2 largest sum in the priority queue
                
                else
                {
                    if(sum > q.top()) // now if you get a sum greater than min heap top element, remove top and add the new one
                    {
                        q.pop();
                        q.push(sum);
                    }
                }
            }
        }
        
        return q.top();
    }
};
