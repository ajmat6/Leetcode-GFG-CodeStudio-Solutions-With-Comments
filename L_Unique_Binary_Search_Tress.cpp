class Solution {
public:
    int numTrees(int n) {
        if(n<=1) return 1;

        // stroing the ans:
        int ans = 0;

        // taking each value as a head:
        for(int i=1; i<=n; i++)
        {
            ans += numTrees(i-1) * numTrees(n-i);
        }

        return ans;
    }
};