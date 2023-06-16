class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;

        // finding powers of 2 till 30:
        int ans = 1;
        for(int i=1; i<=30; i++)
        {
            ans = ans * 2;
            if(n ==  ans) return true;
        }

        return false;
    }
};