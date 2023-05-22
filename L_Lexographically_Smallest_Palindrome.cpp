class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;
        
        while(low < high)
        {
            if(s[low] == s[high])
            {
                low++;
                high--;
                continue;
            }
            
            else
            {
                int lexo1 = s[low] - 'a';
                int lexo2 = s[high] - 'a';
                
                if(lexo1 < lexo2)
                {
                    s[high] = s[low];
                }
                
                else
                {
                    s[low] = s[high];
                }
            }
            
            low++;
            high--;
        }
        
        return s;
    }
};