class Solution {
public:
    int bitwiseComplement(int n) {
        int notOfN = (~n);

        if(n == 0) return 1;

        // Finding the mask:
        int mask = 0;
        while(n != 0)
        {
            // Making last n digits as 1 of mask where n is the last position of 1 in n from last:
            mask = mask << 1;

            mask = mask | 1;

            // now right shift n:
            n = n >> 1;
        } 

        int ans = notOfN & mask;
        return ans;
    }
};