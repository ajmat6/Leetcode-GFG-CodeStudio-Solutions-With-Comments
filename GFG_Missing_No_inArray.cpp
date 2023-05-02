class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        sort(array.begin(), array.end());
        
        for(int i=0; i<n; i++)
        {
            if(array[i] == i + 2) return i+1;
        }
    }
};