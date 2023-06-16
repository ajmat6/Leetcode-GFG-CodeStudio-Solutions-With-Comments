class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int sum = 0;
        int left = 0;
        int right = 0;
        
        while(right < arr.size())
        {
            sum += arr[right];
            
            while(left < right && sum > s)
            {
                sum -= arr[left];
                left++;
            }
            
            if(sum == s) return {left + 1, right + 1};
            right++;
        }
        
        return {-1};
    }
};