class Solution {
public:
    int bulbSwitch(int n) {
        // Approach 1st:
        int count = 0; //for counting no of square nos below n
        int i = 1;

        while(i*i <= n)
        {
            i++;
            count++;
        }
        return count;

        // Approach 2nd:
        // return sqrt(n);
    }
};