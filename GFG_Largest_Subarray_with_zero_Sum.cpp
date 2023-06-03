class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> myMap;
        int sum = 0;
        int ans = 0;
        
        for(int i=0; i<A.size(); i++)
        {
            sum += A[i];
            
            if(sum == 0) ans = i + 1;
            
            if(myMap.find(sum) != myMap.end())
            {
                ans = max(ans, i - myMap[sum]);
            }
            
            else
            {
                myMap[sum] = i;
            }
        }
        
        return ans;
    }
};