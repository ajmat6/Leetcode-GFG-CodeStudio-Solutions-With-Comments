class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans = "";
        int size = arr[0].size();
        
        for(int i=0; i<size; i++)
        {
            int flag = 0;
            for(int j=1; j<N; j++)
            {
                if(arr[0][i] != arr[j][i])
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0) ans.push_back(arr[0][i]);
            else break;
        }
        
        if(ans.size() == 0) return "-1";
        else return ans;
    }
};