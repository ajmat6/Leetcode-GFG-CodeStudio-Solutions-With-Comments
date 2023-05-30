class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > q;
        long long ans = 0;
        
        // creating a min heap:
        for(long long i=0; i<n; i++)
        {
            q.push(arr[i]);
        }
        
        while(q.size() > 1)
        {
            long long a = q.top();
            q.pop();
            
            long long b = q.top();
            q.pop();
            
            long long sum = a + b;
            ans += sum;
            
            q.push(sum);
        }
        
        return ans;
    }
};