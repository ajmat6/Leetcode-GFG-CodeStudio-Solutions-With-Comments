// TC = O(n)
// SC = O(n)
queue<int> rev(queue<int> q)
{
    stack<int> ans; //for storing the popped elements from the queue
    
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        ans.push(s);
    }
    
    while(!ans.empty())
    {
        int s = ans.top();
        ans.pop();
        q.push(s);
    }
    
    return q;
}
