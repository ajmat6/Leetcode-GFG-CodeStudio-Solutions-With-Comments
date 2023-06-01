// TC = O(n*KlogK) -> as size of priority queue is K and we are inserting each element of the K LL of size n into the Min Heap
// SC = O(K) as it is the size of the Min heap to store Min three elements

// MinHeap greater function for our LL DS as it is not int
class MyGreater
{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, MyGreater> q;

        // inserting first element of each LL into the Min Heap:
        for(int i=0; i<lists.size(); i++)
        {
            // checking for the first element of all K LL should not be NULL
            if(lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }

        // Creating pointers to return a LL:
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!q.empty())
        { 
            ListNode* temp = q.top();
            q.pop();

            if(head == NULL)
            {
                head = temp;
                tail = temp;

                // pushing next element of that particula LL into Min Heap if it exist
                if(head -> next != NULL) 
                {
                    q.push(head -> next);
                }
            }

            else
            {
                tail -> next = temp;
                tail = tail -> next;
                
                if(tail -> next != NULL)
                {
                    q.push(tail -> next);
                }
            }
        }

        return head;
    }
};