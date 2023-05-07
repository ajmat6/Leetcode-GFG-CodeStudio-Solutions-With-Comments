#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    queue<int> neww;
    int n = q.size();

    for(int i=0; i<n/2; i++)
    {
        int val = q.front();
        q.pop();
        neww.push(val);
    }

    while(!neww.empty())
    {
        int val = neww.front();
        neww.pop();
        q.push(val);
        int val2 = q.front();
        q.pop();
        q.push(val2);
    }
}