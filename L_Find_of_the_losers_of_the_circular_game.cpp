class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> ans;
        int i = 0;
        int mul = 1;
        
        vector<int> temp (n, 0); // for tracking of the children who got the ball
        temp[0] = 1; // marking first children true;
        
        i = (i + (mul * k)) % n; // circular increament
        
        while(true)
        {
            if(temp[i]) break;
            temp[i] = 1;
            mul++;
            i = (i + (mul * k)) % n;
        }
        
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] == 0)
            {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};
