class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* t1 = head;
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int> pairs;
        stack<int> s;

        //pushing node values of LL into stack
        while(t1 != NULL)
        {
            int val = t1 -> val;
            s.push(val);
            t1 = t1 -> next;
        }

        t1 = head;

        //finding the middle element of the linked list
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //pushing the twin sums into the pairs vector
        while(slow != NULL)
        {
            int sum = t1 -> val + s.top();
            pairs.push_back(sum);
            s.pop();
            t1 = t1 -> next;
            slow = slow -> next;
        }

        //finding the maximum twin sum
        int maxsum = INT_MIN;
        for(int i=0; i<pairs.size(); i++)
        {
            maxsum = max(maxsum, pairs[i]);
        }

        return maxsum;
    }
};
