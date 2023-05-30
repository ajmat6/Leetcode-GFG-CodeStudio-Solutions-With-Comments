class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = num.size() - 1;
        
        while(i >= 0)
        {
            if(num[i] != '0')
            {
                break;
            }
            
            else i--;
        }
        
        num.erase(num.begin() + i + 1, num.end());
        return num;
    }
};