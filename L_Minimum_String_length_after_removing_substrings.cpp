class Solution {
public:
    int minLength(string s) {
        string s1 = "AB";
        string s2 = "CD";
        
        while(true)
        {
            int flag = 0;
            
            if(s.find(s1) != -1)
            {
                int index = s.find(s1);
                s.erase(index, 2);
                flag = 1;
            }
            
            if(s.find(s2) != -1)
            {
                int index = s.find(s2);
                s.erase(index, 2);
                flag = 1;
            }
            
            if(flag == 0) break;
        }
        
        return s.size();
    }
};