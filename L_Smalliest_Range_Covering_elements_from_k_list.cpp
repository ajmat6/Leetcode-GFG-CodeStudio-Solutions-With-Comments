class Solution {
public:
    class Node
    {
        public:
            int data;
            int row;
            int col;

            Node(int data, int row, int col)
            {
                this -> data = data;
                this -> row = row;
                this -> col = col;
            }
    };

    class HeapGreater
    {
        public:
            bool operator()(Node* a, Node* b)
            {
                return a -> data > b -> data;
            }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, HeapGreater> q; // Min Heap
        int mini = INT_MAX;
        int maxi = INT_MIN;

        // storing each LL first values into the Min Heap and finding the temporary min and max element:
        for(int i=0; i<nums.size(); i++)
        {
            int element = nums[i][0];
            mini =  min(mini, element);
            maxi = max(maxi, element);
            Node* temp = new Node(element, i, 0);
            q.push(temp);
        }    

        // Making Permanent Max and Min element:
        int RangeStart = mini;
        int RangeEnd = maxi;

        // popping the min element(top element) from the Heap and updating Min and Max:
        while(!q.empty())
        {
            Node* temp = q.top();
            q.pop();

            mini = temp -> data;

            int tempRange = maxi - mini;
            int PermRange = RangeEnd - RangeStart;

            if(tempRange < PermRange)
            {
                RangeStart = mini;
                RangeEnd = maxi;
            }

            // pushing next element of the LL into the heap if it exists
            if(temp -> col+1 < nums[temp -> row].size())
            {
                maxi = max(maxi, nums[temp -> row][temp -> col+1]);
                Node* NewNode = new Node(nums[temp -> row][temp -> col+1], temp -> row, temp -> col+1);
                q.push(NewNode);
            }

            // Otherwise terminate the loop
            else break;
        }

        // Creating ans vector and pushing the range values and returning it:
        vector<int> ans;
        ans.push_back(RangeStart);
        ans.push_back(RangeEnd);

        return ans;
    }
};