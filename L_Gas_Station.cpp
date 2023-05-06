class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int curr = 0;
        int index = 0;

        for(int i=0; i<gas.size(); i++)
        {
            totalGas += gas[i]; //total gas count
            totalCost += cost[i]; //total cost count
            curr += gas[i] - cost[i]; //increasing curr gas

            if(curr < 0) //not able to go to the next station
            {
                index = i + 1;
                curr = 0;
            }
        }

        if(totalGas < totalCost) return -1; //total gas is less than total cost return -1
        else return index;
    }
};