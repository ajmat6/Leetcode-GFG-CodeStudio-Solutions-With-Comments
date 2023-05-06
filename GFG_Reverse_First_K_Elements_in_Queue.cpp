#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> ans;
    
    for(int i=0; i<k; i++)
    {
        ans.push(q.front());
        q.pop();
    }
    
    while(!ans.empty())
    {
        int val = ans.top();
        q.push(val);
        ans.pop();
    }
    
    int a = q.size() - k;
    
    while(a--)
    {
        int s = q.front();
        q.pop();
        q.push(s);
    }
    
    return q;
}
