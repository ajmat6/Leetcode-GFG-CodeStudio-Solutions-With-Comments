class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        
        int sum = 0;
        int toys = 0;
        for(int i=0; i<N; i++)
        {
            if(sum + arr[i] <= K)
            {
                sum += arr[i];
                toys++;
            }
        }
        return toys;
    }
};