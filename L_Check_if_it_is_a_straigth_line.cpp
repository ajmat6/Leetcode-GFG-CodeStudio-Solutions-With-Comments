class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int xDiff = coordinates[1][1] - coordinates[0][1];
        int yDiff = coordinates[1][0] - coordinates[0][0];

        for(int i=2; i<coordinates.size(); i++)
        {
            if( xDiff*(coordinates[i][0] - coordinates[i-1][0]) != yDiff*(coordinates[i][1] - coordinates[i-1][1])) return false;
        }

        return true;
    }
};