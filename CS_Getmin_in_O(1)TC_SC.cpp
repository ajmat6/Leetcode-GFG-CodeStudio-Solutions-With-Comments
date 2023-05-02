#include<stack>
class SpecialStack {
    //Defining stack:
    stack<int> s;
    int mini = -1;

    public:
        
    void push(int data) {
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }

        else
        {
            if(data < mini)
            {
                s.push(2*data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty())
        {
            return -1;
        }
        
        int popped = s.top();
        s.pop();

        if(popped > mini) return popped;
        else
        {
            int toReturn = mini;
            mini = 2*mini - popped;
            return toReturn;
        }
    }

    int top() {
        if(s.empty()) return -1;
        if(s.top() < mini) return mini;
        else return s.top();
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        return mini;
    }  
};